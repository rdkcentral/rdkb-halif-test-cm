# Unit Testing Suite For cm `HAL`

The following documents should be referenced to provide specific information on the tests required for this module.

[Documentation can be found under "docs/pages" in this repository](docs/pages)

## Table of Contents

- [Version History](#version-history)
- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Description](#description)
- [Reference Documents](#reference-documents)

## Version History

| Date | Comment | Version |
| --- | --- | --- |
| 01/11/24 | Initial Release | 1.0.0 |

## Acronyms, Terms and Abbreviations

- `L1` - Functional Tests
- `HAL`- Hardware Abstraction Layer

## Description

This repository contains the Unit Test Suites (L1) for cm `HAL` 

## Populate Profile File

The users of CM hal L1 test suite can populate the appropriate platform specific values for the parameters filename and HttpUrl in the "cm_profile.yaml" file before executing the hal test binary.

## Reference Documents

|SNo|Document Name|Document Description|Document Link|
|---|-------------|--------------------|-------------|
|1|`HAL` Specification Document|This document provides specific information on the APIs for which tests are written in this module|[CMhalSpec.md](https://github.com/rdkcentral/rdkb-halif-cm/blob/main/docs/pages/CMhalSpec.md "CMhalSpec.md")|
|2|`L1` Tests |`L1` Test Case File for this module |[test_l1_cm_hal.c](src/test_l1_cm_hal.c "test_l1_cm_hal.c")|
