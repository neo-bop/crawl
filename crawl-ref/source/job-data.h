#pragma once

#include <vector>

#include "tag-version.h"

using std::vector;

enum weapon_choice
{
    WCHOICE_NONE,   ///< No weapon choice
    WCHOICE_PLAIN,  ///< Normal weapon choice
    WCHOICE_GOOD,   ///< Chooses from "good" weapons
    WCHOICE_RANGED, ///< Choice of ranged weapon
};

struct job_def
{
    const char* abbrev; ///< Two-letter abbreviation
    const char* name; ///< Long name
    int s, i, d; ///< Starting Str, Int, and Dex
    /// Which species are good at it
    /// No recommended species = job is disabled
    vector<species_type> recommended_species;
    /// What spells start out in their library?
    /// The first spell in the list will be memorised at the start of the game,
    /// if it's level 1 and not useless.
    vector<spell_type> library;
    /// Guaranteed starting equipment. Uses vault spec syntax, with the plus:,
    /// charges:, q:, and ego: tags supported.
    vector<string> equipment;
    weapon_choice wchoice; ///< how the weapon is chosen, if any
    vector<pair<skill_type, int>> skills; ///< starting skills
};

static const map<job_type, job_def> job_data =
{

{ JOB_ABYSSAL_KNIGHT, {
    "AK", "Abyssal Knight",
    5, 2, 5,
    { SP_HILL_ORC, SP_PALENTONGA, SP_TROLL, SP_MERFOLK, SP_BASE_DRACONIAN,
      SP_DEMONSPAWN, },
    { },
    { "leather armour" },
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 3 }, { SK_ARMOUR, 1 }, { SK_DODGING, 1 },
      { SK_INVOCATIONS, 2 }, { SK_WEAPON, 2 }, },
} },

{ JOB_AIR_ELEMENTALIST, {
    "AE", "Air Elementalist",
    0, 7, 5,
    { SP_DEEP_ELF, SP_TENGU, SP_BASE_DRACONIAN, SP_NAGA, SP_VINE_STALKER,
      SP_DJINNI, },
    {
        SPELL_SHOCK,
        SPELL_DISCHARGE,
        SPELL_SWIFTNESS,
        SPELL_AIRSTRIKE,
    },
    { "robe", "potion of magic" },
    WCHOICE_NONE,
    { { SK_CONJURATIONS, 1 }, { SK_AIR_MAGIC, 3 }, { SK_SPELLCASTING, 2 },
      { SK_DODGING, 2 }, { SK_STEALTH, 2 }, },
} },

{ JOB_ARCANE_MARKSMAN, {
    "AM", "Arcane Marksman",
    2, 5, 5,
    { SP_FORMICID, SP_DEEP_ELF, SP_KOBOLD, SP_SPRIGGAN, SP_TROLL, },
    {
        SPELL_SLOW,
        SPELL_INNER_FLAME,
        SPELL_PORTAL_PROJECTILE,
        SPELL_CAUSE_FEAR,
    },
    { "robe", "scroll of vulnerability" },
    WCHOICE_RANGED,
    { { SK_FIGHTING, 1 }, { SK_DODGING, 2 }, { SK_SPELLCASTING, 1 },
      { SK_HEXES, 3 }, { SK_WEAPON, 2 }, },
} },

{ JOB_ARTIFICER, {
    "Ar", "Artificer",
    4, 3, 5,
    { SP_DEEP_DWARF, SP_KOBOLD, SP_SPRIGGAN, SP_BASE_DRACONIAN, SP_DEMONSPAWN, },
    { },
    { "club", "leather armour", "wand of flame charges:15",
      "wand of charming charges:15", "wand of iceblast charges:9" },
    WCHOICE_NONE,
    { { SK_EVOCATIONS, 3 }, { SK_DODGING, 1 }, { SK_FIGHTING, 1 },
      { SK_ARMOUR, 1 }, { SK_STEALTH, 1 }, },
} },

{ JOB_BERSERKER, {
    "Be", "Berserker",
    9, -1, 4,
    { SP_HILL_ORC, SP_OGRE, SP_MERFOLK, SP_MINOTAUR, SP_GARGOYLE, SP_PALENTONGA, },
    { },
    { "animal skin" },
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 3 }, { SK_DODGING, 2 }, { SK_WEAPON, 3 }, },
} },

{ JOB_BRIGAND, {
    "Br", "Brigand",
    3, 3, 6,
    { SP_TROLL, SP_SPRIGGAN, SP_DEMONSPAWN, SP_VAMPIRE, SP_VINE_STALKER, },
    { },
    { "dagger plus:2", "robe", "cloak", "dart ego:poisoned q:9",
      "dart ego:curare q:3" },
    WCHOICE_NONE,
    { { SK_FIGHTING, 2 }, { SK_DODGING, 1 }, { SK_STEALTH, 4 },
      { SK_THROWING, 2 }, { SK_WEAPON, 2 }, },
} },

{ JOB_CHAOS_KNIGHT, {
    "CK", "Chaos Knight",
    4, 4, 4,
    { SP_HILL_ORC, SP_TROLL, SP_GNOLL, SP_MERFOLK, SP_MINOTAUR,
      SP_BASE_DRACONIAN, SP_DEMONSPAWN, },
    { },
    { "leather armour plus:2", "piece from Xom's chessboard" },
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 3 }, { SK_ARMOUR, 1 }, { SK_DODGING, 1 },
      { SK_WEAPON, 3 } },
} },

{ JOB_CINDER_ACOLYTE, {
    "CA", "Cinder Acolyte",
    6, 6, 0,
    { SP_HILL_ORC, SP_BASE_DRACONIAN, SP_OGRE, SP_DJINNI, SP_GNOLL },
    { SPELL_SCORCH },
    { "robe" },
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 3 }, { SK_WEAPON, 3 },
      { SK_FIRE_MAGIC, 3 }, {SK_SPELLCASTING, 1} },
} },

{ JOB_CONJURER, {
    "Cj", "Conjurer",
    -1, 10, 3,
    { SP_DEEP_ELF, SP_NAGA, SP_TENGU, SP_BASE_DRACONIAN, SP_DEMIGOD, SP_DJINNI, },
    {
        SPELL_MAGIC_DART,
        SPELL_SEARING_RAY,
        SPELL_DAZZLING_FLASH,
        SPELL_FULMINANT_PRISM,
        SPELL_ISKENDERUNS_MYSTIC_BLAST,
    },
    { "robe", "potion of magic" },
    WCHOICE_NONE,
    { { SK_CONJURATIONS, 4 }, { SK_SPELLCASTING, 2 }, { SK_DODGING, 2 },
      { SK_STEALTH, 2 }, },
} },

{ JOB_EARTH_ELEMENTALIST, {
    "EE", "Earth Elementalist",
    0, 7, 5,
    { SP_DEEP_ELF, SP_DEEP_DWARF, SP_SPRIGGAN, SP_GARGOYLE, SP_DEMIGOD,
      SP_GHOUL, SP_OCTOPODE, },
    {
        SPELL_SANDBLAST,
        SPELL_PASSWALL,
        SPELL_STONE_ARROW,
        SPELL_PETRIFY,
    },
    { "stone q:30", "robe", "potion of magic", },
    WCHOICE_NONE,
    { { SK_TRANSMUTATIONS, 1 }, { SK_EARTH_MAGIC, 3 }, { SK_SPELLCASTING, 2 },
      { SK_DODGING, 2 }, { SK_STEALTH, 2 }, }
} },

{ JOB_ENCHANTER, {
    "En", "Enchanter",
    0, 7, 5,
    { SP_DEEP_ELF, SP_FELID, SP_KOBOLD, SP_SPRIGGAN, SP_NAGA, SP_VAMPIRE, },
    {
        SPELL_HIBERNATION,
        SPELL_CONFUSING_TOUCH,
        SPELL_TUKIMAS_DANCE,
        SPELL_DAZZLING_FLASH,
    },
    { "dagger plus:1", "robe", "potion of invisibility q:2" },
    WCHOICE_NONE,
    { { SK_WEAPON, 1 }, { SK_HEXES, 3 }, { SK_SPELLCASTING, 2 },
      { SK_DODGING, 2 }, { SK_STEALTH, 3 }, },
} },

{ JOB_FIGHTER, {
    "Fi", "Fighter",
    8, 0, 4,
    { SP_DEEP_DWARF, SP_HILL_ORC, SP_TROLL, SP_MINOTAUR, SP_GARGOYLE,
      SP_PALENTONGA, },
    { },
    { "scale mail", "buckler", "potion of might" },
    WCHOICE_GOOD,
    { { SK_FIGHTING, 3 }, { SK_SHIELDS, 3 }, { SK_ARMOUR, 3 },
      { SK_WEAPON, 2 } },
} },

{ JOB_FIRE_ELEMENTALIST, {
    "FE", "Fire Elementalist",
    0, 7, 5,
    { SP_DEEP_ELF, SP_HILL_ORC, SP_NAGA, SP_TENGU, SP_DEMIGOD, SP_GARGOYLE,
      SP_DJINNI, },
    {
        SPELL_FOXFIRE,
        SPELL_SCORCH,
        SPELL_CONJURE_FLAME,
        SPELL_INNER_FLAME,
        SPELL_FLAME_WAVE,
    },
    { "robe", "potion of magic" },
    WCHOICE_NONE,
    { { SK_CONJURATIONS, 1 }, { SK_FIRE_MAGIC, 3 }, { SK_SPELLCASTING, 2 },
      { SK_DODGING, 2 }, { SK_STEALTH, 2 }, },
} },

{ JOB_GLADIATOR, {
    "Gl", "Gladiator",
    6, 0, 6,
    { SP_DEEP_DWARF, SP_HILL_ORC, SP_MERFOLK, SP_MINOTAUR, SP_GARGOYLE,
      SP_GNOLL, },
    { },
    { "leather armour", "helmet", "throwing net q:3" },
    WCHOICE_GOOD,
    { { SK_FIGHTING, 2 }, { SK_THROWING, 2 }, { SK_DODGING, 3 },
      { SK_WEAPON, 3}, },
} },

{ JOB_HUNTER, {
    "Hu", "Hunter",
    4, 3, 5,
    { SP_HILL_ORC, SP_MINOTAUR, SP_GNOLL, SP_KOBOLD, SP_OGRE, SP_TROLL, },
    { },
    { "leather armour", "scroll of immolation" },
    WCHOICE_RANGED,
    { { SK_FIGHTING, 2 }, { SK_DODGING, 2 }, { SK_STEALTH, 1 },
      { SK_WEAPON, 4 }, },
} },

{ JOB_ICE_ELEMENTALIST, {
    "IE", "Ice Elementalist",
    0, 7, 5,
    { SP_MERFOLK, SP_NAGA, SP_BASE_DRACONIAN, SP_DEMIGOD,
      SP_GARGOYLE, SP_DJINNI, },
    {
        SPELL_FREEZE,
        SPELL_FROZEN_RAMPARTS,
        SPELL_OZOCUBUS_ARMOUR,
        SPELL_HAILSTORM,
    },
    { "robe", "potion of magic" },
    WCHOICE_NONE,
    { { SK_ICE_MAGIC, 4 }, { SK_SPELLCASTING, 2 },
      { SK_DODGING, 2 }, { SK_STEALTH, 2 }, },
} },

{ JOB_DELVER, {
    "De", "Delver",
    4, 2, 6,
    { SP_FELID, SP_SPRIGGAN, SP_KOBOLD, SP_VAMPIRE, SP_GNOLL },
    { },
    { "leather armour", "scroll of fog", "scroll of magic mapping",
      "scroll of fear", "potion of haste", "wand of digging charges:3" },
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 3 }, { SK_DODGING, 2 }, { SK_STEALTH, 5 }, { SK_WEAPON, 2 }, },
} },

{ JOB_MONK, {
    "Mo", "Monk",
    3, 2, 7,
    { SP_DEEP_DWARF, SP_HILL_ORC, SP_TROLL, SP_PALENTONGA, SP_MERFOLK,
      SP_GARGOYLE, SP_DEMONSPAWN, },
    { },
    { "robe", "potion of ambrosia" },
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 3 }, { SK_WEAPON, 3 }, { SK_DODGING, 3 },
      { SK_STEALTH, 2 }, },
} },

{ JOB_NECROMANCER, {
    "Ne", "Necromancer",
    0, 7, 5,
    { SP_DEEP_ELF, SP_DEEP_DWARF, SP_HILL_ORC, SP_DEMONSPAWN, SP_MUMMY,
      SP_VAMPIRE, },
    {
        SPELL_PAIN,
        SPELL_ANIMATE_SKELETON,
        SPELL_VAMPIRIC_DRAINING,
        SPELL_ANIMATE_DEAD,
        SPELL_AGONY,
    },
    { "robe", "potion of magic" },
    WCHOICE_NONE,
    { { SK_SPELLCASTING, 2 }, { SK_NECROMANCY, 4 }, { SK_DODGING, 2 },
      { SK_STEALTH, 2 }, },
} },

{ JOB_SUMMONER, {
    "Su", "Summoner",
    0, 7, 5,
    { SP_DEEP_ELF, SP_HILL_ORC, SP_VINE_STALKER, SP_MERFOLK, SP_TENGU,
      SP_VAMPIRE, },
    {
        SPELL_SUMMON_SMALL_MAMMAL,
        SPELL_CALL_IMP,
        SPELL_CALL_CANINE_FAMILIAR,
        SPELL_SUMMON_GUARDIAN_GOLEM,
        SPELL_SUMMON_LIGHTNING_SPIRE,
    },
    { "robe", "potion of magic" },
    WCHOICE_NONE,
    { { SK_SUMMONINGS, 4 }, { SK_SPELLCASTING, 2 }, { SK_DODGING, 2 },
      { SK_STEALTH, 2 }, },
} },

{ JOB_TRANSMUTER, {
    "Tm", "Transmuter",
    2, 5, 5,
    { SP_NAGA, SP_MERFOLK, SP_BASE_DRACONIAN, SP_DEMIGOD, SP_DEMONSPAWN,
      SP_TROLL, },
    {
        SPELL_BEASTLY_APPENDAGE,
        SPELL_WEREBLOOD,
        SPELL_SPIDER_FORM,
        SPELL_ICE_FORM,
    },
    { "robe", "potion of lignification" },
    WCHOICE_NONE,
    { { SK_FIGHTING, 1 }, { SK_UNARMED_COMBAT, 3 }, { SK_DODGING, 2 },
      { SK_SPELLCASTING, 2 }, { SK_TRANSMUTATIONS, 2 }, },
} },

{ JOB_VENOM_MAGE, {
    "VM", "Venom Mage",
    0, 7, 5,
    { SP_DEEP_ELF, SP_SPRIGGAN, SP_NAGA, SP_MERFOLK, SP_TENGU, SP_DJINNI,
      SP_DEMONSPAWN, },
    {
        SPELL_STING,
        SPELL_POISONOUS_VAPOURS,
        SPELL_MEPHITIC_CLOUD,
        SPELL_OLGREBS_TOXIC_RADIANCE,
    },
    { "robe", "potion of magic" },
    WCHOICE_NONE,
    { { SK_TRANSMUTATIONS, 1 }, { SK_POISON_MAGIC, 3 }, { SK_SPELLCASTING, 2 },
      { SK_DODGING, 2 }, { SK_STEALTH, 2 }, },
} },

{ JOB_WANDERER, {
    "Wn", "Wanderer",
    0, 0, 0, // Randomised
    { SP_HILL_ORC, SP_SPRIGGAN, SP_GNOLL, SP_MERFOLK, SP_BASE_DRACONIAN,
      SP_HUMAN, SP_DEMONSPAWN, },
    { }, // Randomised
    { }, // Randomised
    WCHOICE_NONE,
    { }, // Randomised
} },

{ JOB_WARPER, {
    "Wr", "Warper",
    3, 5, 4,
    { SP_FELID, SP_DEEP_DWARF, SP_SPRIGGAN, SP_PALENTONGA, SP_BASE_DRACONIAN, },
    {
        SPELL_BLINK,
        SPELL_BECKONING,
        SPELL_GRAVITAS,
        SPELL_TELEPORT_OTHER,
        SPELL_MANIFOLD_ASSAULT,
    },
    { "leather armour", "scroll of blinking", "boomerang ego:dispersal q:7" },
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 2 }, { SK_ARMOUR, 1 }, { SK_DODGING, 2 },
      { SK_SPELLCASTING, 2 }, { SK_TRANSLOCATIONS, 3 }, { SK_THROWING, 1 },
      { SK_WEAPON, 2 }, },
} },

{ JOB_WIZARD, {
    "Wz", "Hedge Wizard",
    2, 6, 4,
    { SP_DEEP_ELF, SP_NAGA, SP_BASE_DRACONIAN, SP_OCTOPODE, SP_HUMAN,
      SP_DJINNI, },
    {
        SPELL_MAGIC_DART,
        SPELL_BLINK,
        SPELL_CALL_IMP,
        SPELL_SLOW,
        SPELL_CONJURE_FLAME,
        SPELL_MEPHITIC_CLOUD,
    },
    { "dagger", "robe", "hat", "potion of magic" },
    WCHOICE_NONE,
    { { SK_DODGING, 2 }, { SK_STEALTH, 2 }, { SK_SPELLCASTING, 3 },
      { SK_TRANSLOCATIONS, 1 }, { SK_CONJURATIONS, 1 }, { SK_SUMMONINGS, 1 }, },
} },
#if TAG_MAJOR_VERSION == 34
{ JOB_SKALD, {
    "Sk", "Skald",
    0, 0, 0,
    { },
    { },
    { },
    WCHOICE_NONE,
    { },
} },

{ JOB_DEATH_KNIGHT, {
    "DK", "Death Knight",
    0, 0, 0,
    { },
    { },
    { },
    WCHOICE_NONE,
    { },
} },

{ JOB_HEALER, {
    "He", "Healer",
    0, 0, 0,
    { },
    { },
    { },
    WCHOICE_NONE,
    { },
} },

{ JOB_JESTER, {
    "Jr", "Jester",
    0, 0, 0,
    { },
    { },
    { },
    WCHOICE_NONE,
    { },
} },

{ JOB_PRIEST, {
    "Pr", "Priest",
    0, 0, 0,
    { },
    { },
    { },
    WCHOICE_NONE,
    { },
} },

{ JOB_STALKER, {
    "St", "Stalker",
    0, 0, 0,
    { },
    { },
    { },
    WCHOICE_NONE,
    { },
} },
#endif
};
