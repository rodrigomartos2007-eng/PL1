.PHONY: clean All

All:
	@echo "----------Building project:[ PECLMartosLagunaRodrigo - Debug ]----------"
	@"$(MAKE)" -f  "PECLMartosLagunaRodrigo.mk"
clean:
	@echo "----------Cleaning project:[ PECLMartosLagunaRodrigo - Debug ]----------"
	@"$(MAKE)" -f  "PECLMartosLagunaRodrigo.mk" clean
