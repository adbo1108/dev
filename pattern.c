[InitTester2UnitReady]


dwInitTester2UnitReady(HW_RESET, WO_SSU_POWER_DOWN_BEFORE_INIT)

->
		//======================== Set Init Flag
		Phison_printf("%d %d %d INFO - set device init flag ", LOG_GROUP_Test_Pattern, LOG_PATTERN_MSG_NO_Info, LOG_PATTERN_MSG_NO_Info);
		if ((dwStatus = UFS_Set_Flag(DEVIC_INIT)) != UFS_STATUS_OK){
			Phison_printf("%d %d %d ERROR - Function %s", LOG_GROUP_Test_Pattern, LOG_PATTERN_MSG_TYPE_Error, LOG_PATTERN_MSG_NO_Function_Error, "UFS_Set_Flag");
			goto SKIP_OR_EXIT;
		}

		do {
			if ((dwStatus = UFS_Read_Flag(DEVIC_INIT, dwFlagValue)) != UFS_STATUS_OK){
				Phison_printf("%d %d %d ERROR - Function %s", LOG_GROUP_Test_Pattern, LOG_PATTERN_MSG_TYPE_Error, LOG_PATTERN_MSG_NO_Function_Error, "UFS_Read_Flag");
				goto SKIP_OR_EXIT;
			}

#ifdef	FPGA_DEVICE
		Sleep(3000);
#else
			Sleep(10);
#endif
			byFlagCount++;
			if (byFlagCount > 100){
				Phison_printf("%d %d %d ERROR - DEVICE_INIT flag not clear after 100 times polling", LOG_GROUP_Test_Pattern, LOG_PATTERN_MSG_TYPE_Error, LOG_PATTERN_MSG_NO_Error);
				dwStatus = UFS_DEVICE_INIT_FAIL;
				goto SKIP_OR_EXIT;
			}
			Phison_printf("%d %d %d INFO - read device init flag = %d ", LOG_GROUP_Test_Pattern, LOG_PATTERN_MSG_NO_Info, LOG_PATTERN_MSG_NO_Info, dwFlagValue);
		} while (dwFlagValue == DEVICE_INIT_NOT_FINISHED);
	//}




CheckAllRegisterValue



EraseAllMeasureCurent





MultiWriteFullOfAllDevice



RecoveryFlow