/*
 * MACRO.h
 *
 * Created: 12/20/2022 1:20:21 AM
 *  Author: 20100
 */ 


#ifndef MACRO_H_
#define MACRO_H_

#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)		reg|=(1<<bit)
#define CLR_BIT(reg,bit)        reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)		reg^=(1<<bit)
#define READ_BIT(reg,bit)		((reg&(1u<<bit))>>bit)
#define IS_BIT_SET(reg,bit)		(reg&(1u<<bit))>>bit
#define IS_BIT_CLR(reg,bit)		!((reg&(1u<<bit))>>bit)
#define ROR(reg,num)			reg=(reg<<(REGISTER_SIZE-num)) | (reg>(num))
#define ROL(reg,num)			reg=(reg>>(REGISTER_SIZE-num)) | (reg>(num))



#endif /* MACRO_H_ */