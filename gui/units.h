/*	Public domain	*/

#ifndef _AGAR_WIDGET_UNITS_H_
#define _AGAR_WIDGET_UNITS_H_

#include <agar/config/historical_units.h>

#include <agar/gui/begin.h>

typedef struct ag_unit {
	char *key;		/* Key */
	char *abbr;		/* Symbol */
	char *name;		/* Long name */
	double divider;		/* Base unit divider (for linear conv) */
	double (*func)(double, int);	/* For nonlinear conversions */
} AG_Unit;

__BEGIN_DECLS
const AG_Unit	  *AG_FindUnit(const char *);
const AG_Unit	  *AG_BestUnit(const AG_Unit[], double);
int	   	   AG_UnitFormat(double, const AG_Unit[], char *, size_t);

double	AG_UnitFahrenheit(double, int);
double	AG_UnitCelsius(double, int);
#ifdef HISTORICAL_UNITS
double	AG_UnitRankine(double, int);
double	AG_UnitReaumur(double, int);
#endif

extern const AG_Unit *agUnitGroups[];
extern const char *agUnitGroupNames[];
extern const int agnUnitGroups;

extern const AG_Unit agIdentityUnit[];
extern const AG_Unit agLengthUnits[];
extern const AG_Unit agAngleUnits[];
extern const AG_Unit agVideoUnits[];
extern const AG_Unit agAreaUnits[];
extern const AG_Unit agVolumeUnits[];
extern const AG_Unit agSpeedUnits[];
extern const AG_Unit agMassUnits[];
extern const AG_Unit agTimeUnits[];
extern const AG_Unit agCurrentUnits[];
extern const AG_Unit agTemperatureUnits[];
extern const AG_Unit agSubstanceAmountUnits[];
extern const AG_Unit agLightUnits[];
extern const AG_Unit agPowerUnits[];
extern const AG_Unit agEMFUnits[];
extern const AG_Unit agResistanceUnits[];
extern const AG_Unit agResistanceTC1Units[];
extern const AG_Unit agResistanceTC2Units[];
extern const AG_Unit agCapacitanceUnits[];
extern const AG_Unit agInductanceUnits[];
extern const AG_Unit agFrequencyUnits[];
extern const AG_Unit agPressureUnits[];
extern const AG_Unit agMetabolicExpenditureUnits[];
extern const AG_Unit agPercentageUnits[];
extern const AG_Unit agKUnits[];
extern const AG_Unit agVacuumUnits[];

static __inline__ double
AG_Unit2Base(double n, const AG_Unit *unit)
{
	return (unit->func != NULL ? unit->func(n, 1) : n*unit->divider);
}
static __inline__ double
AG_Base2Unit(double n, const AG_Unit *unit)
{
	return (unit->func != NULL ? unit->func(n, 0) : n/unit->divider);
}
static __inline__ double
AG_Unit2Unit(double n, const AG_Unit *ufrom, const AG_Unit *uto)
{
	return (AG_Base2Unit(AG_Unit2Base(n, ufrom), uto));
}
static __inline__ const char *
AG_UnitAbbr(const AG_Unit *unit)
{
	return (unit->abbr[0] != '\0' ? unit->abbr : unit->key);
}

#define	AG_Unit2Basef(n, u) ((float)AG_Unit2Base((float)(n), (u)))
#define	AG_Base2Unitf(n, u) ((float)AG_Base2Unit((float)(n), (u)))
#define	AG_Unit2Unitf(n, u1, u2) ((float)AG_Unit2Unit((float)(n), (u1), (u2)))
__END_DECLS

#include <agar/gui/close.h>
#endif /* _AGAR_WIDGET_UNITS_H_ */
