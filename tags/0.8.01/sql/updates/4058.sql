ALTER TABLE `item_template` ADD COLUMN `ArmorDamageModifier` float NOT NULL default '0' AFTER `RequiredDisenchantSkill`;
ALTER TABLE `item_template` DROP COLUMN `name2`, DROP COLUMN `name3`, DROP COLUMN `name4`; 
DELETE FROM  `spell_affect` WHERE `entry` in(11370,12288,12288,12707,12707,14067,15019,16183,16823,16823,16825,16825,17325,18310,18311,18312,18313,29860,29861,29862,30440,30640,30649,33216,33217,34301);
DELETE FROM  `spell_proc_event` WHERE `entry` in(114,637,646,648,1028,1034,1048,1707,2095,2852,4051,4161,4512,5575,5580,6134,6135,6592,6593,7601,7614,7615,7616,7618,9205,9793,9797,9801,9808,10095,10400,10727,10868,11830,11838,11961,12002,12038,12094,12546,12552,13078,13260,13320,13767,13987,14095,14150,14152,14154,15364,15365,15567,15568,15569,15644,15650,16140,16241,16242,16311,16312,16313,16423,16563,16925,16926,16955,16956,16957,16962,16963,16964,17000,17001,17079,17082,19195,19234,19235,19389,19390,19396,19640,20163,20169,20183,20204,20411,20412,20413,20414,20419,20421,20422,20423,20563,20809,20896,21387,21789,22283,22285,22286,22287,22288,22697,22716,23255,23301,23303,23305,23306,25592,25715,25727,25728,25729,25730,25731,25732,25733,25734,25745,25751,25752,25757,25926,25942,25945,26341,28130,28881,29526);