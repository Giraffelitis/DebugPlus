#pragma once

#define __CLASS_FUNCTION__ __FUNCTION__

/* ClassName::FunctionName where this is called. */
#define CURRENT_CLASS_FUNCTION (FString(__FUNCTION__))
/* Class Name where this is called. */
#define CURRENT_CLASS (FString(__FUNCTION__).Left(FString(__FUNCTION__).Find(TEXT(":"))) )
/* Function Name where this is called. */
#define CURRENT_FUNCTION (FString(__FUNCTION__).Right(FString(__FUNCTION__).Len() - FString(__FUNCTION__).Find(TEXT("::")) - 2 ))
/* Line Number where this is called. */
#define CURRENT_LINE (FString::FromInt(__LINE__))
/* Class Name and Line Number where this is called. */
#define CURRENT_CLASS_LINE (CURRENT_CLASS + " (" + CURRENT_LINE + ")")
/* Class Name and Function Name and Line Number where this is called. */
#define CURRENT_CLASS_FUNCTION_LINE (CURRENT_CLASS_FUNCTION + " (" + CURRENT_LINE + ")")
/* Function Signature where this is called. */
#define CURRENT_FUNCTIONSIG (FString(__FUNCSIG__))
/* Create String for Log Category Name from CURRENT_CLASS. */

/*
 * UE_LOG macros
 */

/* Log macro. Style: ClassName::FunctionName Format. */
#define DP_LOG(CategoryName, Verbosity, FormatString, ...) UE_LOG(CategoryName, Verbosity, TEXT("Host: %s %s: %s"), IsRunningDedicatedServer() ? *FString("Server") : *FString("Client"), *CURRENT_CLASS_FUNCTION_LINE, *FString::Printf(TEXT(FormatString), ##__VA_ARGS__ ))

/*
 * Screen Messages macros
 */

#define DP_PRINT(Time, Color, FormatString , ...) if(GEngine)(GEngine->AddOnScreenDebugMessage(-1, Time, FColor::Color, *(CURRENT_CLASS_FUNCTION_LINE + ": " + (FString::Printf(TEXT(FormatString), ##__VA_ARGS__ )))) )

