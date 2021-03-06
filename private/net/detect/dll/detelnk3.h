#define     ELNK3_3C529_10BASET_MCA_ID    0x627c
#define     ELNK3_3C529_10BASE2_MCA_ID    0x627d
#define     ELNK3_3C529_TPONLY_MCA_ID     0x627f

#define     ELNK3_3C579_EISA_ID           0x92506d50
#define     ELNK3_3C509_EISA_ID           0x90506d50






#define	IDCMD_WAIT          0x00	/* Go to ID_WAIT state, actually 0 to 0x7f	*/
#define	IDCMD_READ_PROM	    0x80	/* Read EEPROM word n, n is last six bits	*/
					/* of command					*/
#define	IDCMD_RESET	    0xC0	/* Global reset, same as power on reset		*/
#define	IDCMD_SET_TAG	    0xD0	/* Set Adapter tag to value in last 3 bits	*/
#define	IDCMD_TEST_TAG	    0xD8	/* Test Adapter tag by value in last 3 bits */
#define MAXTAG	7
#define	IDCMD_ACTIVATE	    0xE0	/* Activate adapter, writing last 5 bits	*/
					/* into Address Configuration register		*/
#define	IDCMD_ACTIVATE_FF   0xFF        /* Activate adapter using preconfigured		*/
					/* I/O base address							*/
/*
	Default configuration values for the EtherLink III adapter.
 */

#define DEFAULT_ID_PORT		0x00000110	/* A port (maybe) not being used by */
						/* anything else in an ISA machine */
/*
	Card EEPROM configuration, as shipped.
 */
#define DEFAULT_IO_PORT		(PVOID)0x300
#define DEFAULT_IRQ			10
#define DEFAULT_TRANSCEIVER	TRANSCEIVER_BNC	/* For the 3C509-TP, this will */
											/* be TRANSCEIVER_TP */

// AdaptP->MulticastListMax
//
// the maximum number of different multicast addresses that
// may be specified to this adapter (the list is global for
// all protocols).

#define DEFAULT_MULTICASTLISTMAX 16


/*
	EEPROM data structure.
 */

#define EEPROM_NODE_ADDRESS_0				0
#define EEPROM_NODE_ADDRESS_1				1
#define EEPROM_NODE_ADDRESS_2				2

#define	EEPROM_PRODUCT_ID					3

#define	EEPROM_MANUFACTURING_DATE			4
#define	EEPROM_MANUFACTURING_DATA1			5
#define	EEPROM_MANUFACTURING_DATA2			6
#define	EEPROM_MANUFACTURER_CODE			7

#define	EEPROM_ADDRESS_CONFIGURATION		8
#define	EEPROM_RESOURCE_CONFIGURATION		9

#define	EEPROM_OEM_NODE_0					10
#define	EEPROM_OEM_NODE_1					11
#define	EEPROM_OEM_NODE_2					12

#define	EEPROM_SOFTWARE_INFO				13

#define	EEPROM_RESERVED						14

#define	EEPROM_CHECKSUM						15

#define	EEPROM_NETWORK_MANAGEMENT_DATA_0	16

/*
	Address configuration register.
 */

typedef union ELNK3_Address_Configuration_Register{
	struct{
		USHORT	eacf_iobase : 5;
		USHORT	eacf_reserved : 3;
		USHORT	eacf_ROMbase : 4;
		USHORT	eacf_ROMsize : 2;
		USHORT	eacf_XCVR : 2;
	};
	USHORT eacf_contents;
}ELNK3_Address_Configuration_Register, *PELNK3_Address_Configuration_Register;


/*
	EtherLink III configuration control register.
 */

#define CCR_ENABLE_BIT	0
#define CCR_RESET_BIT	2

#define CCR_ENABLE	( 1 << CCR_ENABLE_BIT )
#define CCR_RESET	( 1 << CCR_RESET_BIT )
/*
	Transceiver configuration as stored in Address Configuration Register.
 */

#define TRANSCEIVER_TP			0	/* Twisted pair transceiver enabled. */
#define TRANSCEIVER_EXTERNAL	1	/* AUI port enabled, using ext. trans. */
#define	TRANSCEIVER_RESERVED	2	/* reserved - undefined */
#define	TRANSCEIVER_BNC			3	/* BNC transceiver enabled */
#define	TRANSCEIVER_UNDEFINED	TRANSCEIVER_RESERVED
									/* Handy dandy undefined transceiver value */

/*
	Conversion from eacf_iobase to I/O port used.
 */
#define IOBASE_EISA	0x31			/* EISA mode slot-specific I/O address */

typedef union EISA_IO_Address {
	struct{
		USHORT	eia_port : 12;
		USHORT	eia_slot : 4;
	};
	USHORT eia_contents;
}EISA_IO_Address, *PEISA_IO_Address;

#define EISA_Window_0_Address	0xC80	/* Window zero is always mapped here */
										/* on an EISA machine configured */
										/* adapter */     
										
/* 
	IOBaseAddress for an EtherLink III configured for EISA operation and installed
	in an EISA slot is the slotnumber times 1000h.
 */										
#define EISA_SlotNumber_To_IOBase(x) ((x) * 0x1000)

#define EACF_IOBASE_TO_ISA_IOBASE(x) ( ( (x) << 4 ) + 0x200 )
#define ISA_IOBASE_TO_EACF_IOBASE(x) ( ( (x) - 0x200 ) >> 4 )

/*
	Elnk III resource configuration register.
 */

typedef union ELNK3_Resource_Configuration_Register{
	struct{
		USHORT	ercf_reserved : 8;
		USHORT	ercf_reserved_F : 4;
		USHORT	ercf_IRQ : 4;
	};
	USHORT ercf_contents;
}ELNK3_Resource_Configuration_Register, *PELNK3_Resource_Configuration_Register;

/*
	Format of command word written to ELNK III command register.
 */

typedef union ELNK3_Command{
	struct{
		USHORT	ec_arg : 11;
		USHORT	ec_command : 5;
	};
	USHORT ec_contents;
}ELNK3_Command,*PELNK3_Command;

#define	EC_GLOBAL_RESET				 0
#define	EC_SELECT_WINDOW			 1
#define	EC_START_COAX_XCVR			 2
#define	EC_RX_DISABLE				 3
#define	EC_RX_ENABLE				 4
#define	EC_RX_RESET				 5

#define	EC_RX_DISCARD_TOP_PACKET        	 8
#define	EC_TX_ENABLE				 9
#define	EC_TX_DISABLE				10
#define	EC_TX_RESET				11

#define	EC_REQUEST_INTERRUPT                    12

#define	EC_INT_LATCH			 1
#define	EC_INT_ADAPTER_FAILURE		 2
#define	EC_INT_TX_COMPLETE		 4
#define	EC_INT_TX_AVAILABLE		 8
#define	EC_INT_RX_COMPLETE		16
#define	EC_INT_RX_EARLY			32
#define	EC_INT_INTERRUPT_REQUESTED	64
#define	EC_INT_UPDATE_STATISTICS        128

#define	EC_ACKNOWLEDGE_INTERRUPT                13
#define	EC_SET_INTERRUPT_MASK		        14
#define	EC_SET_READ_ZERO_MASK		        15

#define EC_SET_RX_EARLY                         17
#define EC_SET_TX_AVAILIBLE                     18


#define	EC_SET_RX_FILTER			16

#define	EC_FILTER_ADDRESS			 1
#define	EC_FILTER_GROUP				 2
#define	EC_FILTER_BROADCAST			 4
#define	EC_FILTER_PROMISCUOUS			 8

//
// Window Numbers
//
#define WNO_SETUP			 0			 // setup/configuration
#define WNO_OPERATING		 1			 // operating set
#define WNO_STATIONADDRESS	 2			 // station address setup/read
#define WNO_FIFO			 3			 // FIFO management
#define WNO_DIAGNOSTICS		 4			 // diagnostics
#define WNO_READABLE		 5			 // registers set by commands
#define WNO_STATISTICS		 6			 // statistics
//
// Port offsets, Window 1
//
#define PORT_CmdStatus		 0x0E		 // command/status
#define PORT_TxFree			 0x0C		 // free transmit bytes
#define PORT_TxStatus		 0x0B 		 // transmit status (byte)
#define PORT_Timer			 0x0A		 // latency timer (byte)
#define PORT_RxStatus		 0x08		 // receive status
#define PORT_RxFIFO			 0x00		 // RxFIFO read
#define PORT_TxFIFO			 0x00		 // TxFIFO write
//
// Port offsets, Window 0
//
#define PORT_EEData			 0x0C		 // EEProm data register
#define PORT_EECmd			 0x0A		 // EEProm command register
#define PORT_CfgResource	 0x08		 // resource configuration
#define PORT_CfgAddress		 0x06		 // address configuration
#define PORT_CfgControl		 0x04		 // configuration control
#define PORT_ProductID		 0x02		 // product id (EISA)
#define PORT_Manufacturer	 0x00		 // Manufacturer code (EISA)
//
// Port offsets, Window 2
//
#define PORT_SA0_1			 0x00		 // station address bytes 0,1
#define PORT_SA2_3			 0x02		 // station address bytes 2,3
#define PORT_SA4_5			 0x04		 // station address bytes 4,5

//
// port offsets, window 3
//
#define PORT_FREE_RX_BYTES       0x0a

//
//
//  Port Offsets window 4
//
#define PORT_FIFO_DIAG           0x04

#define RX_UNDERRUN              0x2000
#define TX_OVERRUN               0x0400


#define PORT_MEDIA_TYPE          0x0a

#define MEDIA_LINK_BEAT          0x0080
#define MEDIA_JABBER             0x0040


#define PORT_NET_DIAG            0x06



//
// board identification codes
//
#define EISA_MANUFACTURER_ID	 0x6D50	 // EISA manufacturer code

#define ISAID_BNC				0x9050	// Product ID for ISA TP board
#define ISAID_TP				0x9051	// Product ID for ISA coax board
#define EISAID					0x9052	// Product ID for EISA board

//...so far the list is 5090=ISA 3C509-TP (TP/AUI), 5091h=ISA 3C509 (BNC/AUI),
//	 5092h=EISA 3C579-TP (TP/AUI) and 5092h=EISA 3C579 (BNC/AUI).  other
//	 bottom nibbles will likely be assigned to TP-only/combo/whatever
//	 else marketting thinks up...

#define PRODUCT_ID_MASK			 0xF0FF  // Mask off revision nibble

#define MCAID_BNC				 0x627C		// MCA Adapter ID: BNC/AUI
#define MCAID_TP				 0x627D		// MCA Adapter ID: TP/AUI
#define MCAID_COMBO				 0x61DB		// MCA Adapter ID: Combo (future)
#define MCAID_TPCOAX			 0x62F6		// MCA Adapter ID: TP/COAX (future)
#define MCAID_TPONLY			 0x62F7		// MCA Adapter ID: TP only (future)

/* 
	Note: This is referred to as POS2 in 3COM's MCA Technical Reference Addendum
	for the EtherLink III.
 */
#define POS1_CDEN	1						// Card enable bit in POS2 register

/* 
	Note: This is referred to as POS4 in 3COM's MCA Technical Reference Addendum
	for the EtherLink III.
 */
#define POS3_TO_IOBASE(x)  		((((x) << 8) & 0xFC00) | 0x0200)
//
// EEProm access
//
#define EE_BUSY					  0x8000  // EEProm busy bit in EECmd
#define EE_TCOM_NODE_ADDR_WORD0	  0x00
#define EE_TCOM_NODE_ADDR_WORD1	  0x1
#define EE_TCOM_NODE_ADDR_WORD2	  0x2
#define EE_VULCAN_PROD_ID		  0x3
#define EE_MANUFACTURING_DATA	  0x4
#define EE_SERIAL_NUMBER_WORD0	  0x5
#define EE_SERIAL_NUMBER_WORD1	  0x6
#define EE_MANUFACTURER_CODE	  0x7
#define EE_ADDR_CONFIGURATION	  0x8
#define EE_RESOURCE_CONFIGURATION 0x9
#define EE_OEM_NODE_ADDR_WORD0	  0xA
#define EE_OEM_NODE_ADDR_WORD1	  0xB
#define EE_OEM_NODE_ADDR_WORD2	  0xC
#define EE_SOFTWARE_CONFIG_INFO	  0xD
#define EE_CWORD				  0xE










typedef struct _ELNK3_ISA_DESCRIPTION {
    USHORT      AddressConfigRegister;
    USHORT      ResourceConfigRegister;
    USHORT      IOPort;
    USHORT      Irq;
    BOOLEAN     Tagged;
    BOOLEAN     Active;
    } ELNK3_ISA_DESCRIPTION, *PELNK3_ISA_DESCRIPTION;
