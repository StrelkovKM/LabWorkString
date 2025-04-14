#include <iostream>
#include <gtest.h>
#include "ClassTString.h"
#include "ClassTConsole.h"

//TEST(TGames, can_create_games_with_positive_count)
//{
//  ASSERT_NO_THROW(TGames bf(3, ""));
//}
//
//TEST(TGames, can_get_count)
//{
//  TGames bf(3, "");
//
//  EXPECT_NEAR(3, bf.GetCount(), 0.000001);
//}
//TEST(TGames, can_copy)
//{
//  TGames bf(3, "");
//  TGames kf(bf);
//}
//
//TEST(TVGames, throws_when_create_game_with_negative_count)
//{
//  ASSERT_ANY_THROW(TGames bf(-3, ""));
//}
//
//
/////TVGames
//
//TEST(TVGames, can_create_vgames_with_positive_count)
//{
//  ASSERT_NO_THROW(TVGames bf("", "", 3));
//}
//
//TEST(TVGames, can_copy)
//{
//  TVGames bf("", "", 3);
//  TVGames kf(bf);
//}
//
//TEST(TVGames, can_get_face)
//{
//  TVGames bf("", "", 3);
//
//  EXPECT_NEAR(3, bf.GetFace(), 0.000001);
//}
//
//TEST(TVGames, throws_when_create_vgame_with_negative_face)
//{
//  ASSERT_ANY_THROW( TVGames bf("", "", -3));
//}
//
/////TVPWatchDogs
//
//TEST(TVPWatchDogs, can_create_TVPWatchDogs_with_positive_chapter)
//{
//  ASSERT_NO_THROW(TVPWatchDogs bf(3));
//}
//
//TEST(TVPWatchDogs, can_get_chapter)
//{
//  TVPWatchDogs bf(3);
//
//  EXPECT_NEAR(3, bf.GetChapter(), 0.000001);
//}
//
//TEST(TVPWatchDogs, can_copy)
//{
//  TVPWatchDogs bf(3);
//  TVPWatchDogs kf(bf);
//}
//
//TEST(TVPWatchDogs, throws_when_create_TVPWatchDogs_with_negative_chapter)
//{
//  ASSERT_ANY_THROW(TVPWatchDogs bf(-3));
//}
//
/////TSWCurling
//
//TEST(TSWCurling, can_create_TSWCurling_with_positive_lenght)
//{
//  ASSERT_NO_THROW(TSWCurling bf(3));
//}
//
//
//TEST(TSWCurling, can_get_lenght)
//{
//  TSWCurling bf(3);
//
//  EXPECT_NEAR(3, bf.GetLenght(), 0.000001);
//}
//
//TEST(TSWCurling, can_copy)
//{
//  TSWCurling bf(3);
//  TSWCurling kf(bf);
//}
//TEST(TSWCurling, throws_when_create_TSWCurling_with_negative_lenght)
//{
//  ASSERT_ANY_THROW(TSWCurling bf(-3));
//}

///Test TString

TEST(TString, can_create_TString)
{
  ASSERT_NO_THROW(TString bf("2", 1));
}
TEST(TString, throws_when_create_TString_nullptr)
{
  ASSERT_ANY_THROW(TString bf(nullptr));
}

TEST(TString, can_copy)
{
  TString bf("");
  TString kf(bf);
}

TEST(TString, throws_when_create_TString_nullptr_negative_len)
{
  ASSERT_ANY_THROW(TString bf(nullptr, -3));
}


TEST(TString, can_get_len)
{
  TString bf("gfg", 3);

  EXPECT_NEAR(3, bf.GetLen(), 0.000001);
}

TEST(TString, can_set_len)
{
  TString bf("gfg", 3);
  bf.SetLen(2);
  EXPECT_NEAR(2, bf.GetLen(), 0.000001);
}



/// Test TConsole

TEST(TConsole, can_create_positive_console)
{
  ASSERT_NO_THROW(TConsole bf(3, 4, 10));
}

TEST(TConsole, can_create_negative_console)
{
  ASSERT_ANY_THROW(TConsole bf(-3, -4, -10));
}

TEST(TConsole, can_get_x)
{
  TConsole bf(3, 3, 3);

  EXPECT_NEAR(3, bf.GetX(), 0.000001);
}

TEST(TString, can_set_x)
{
  TConsole bf(3, 3, 3);
  bf.SetX(3);
  EXPECT_NEAR(3, bf.GetX(), 0.000001);
}

TEST(TConsole, can_get_y)
{
  TConsole bf(3, 3, 3);

  EXPECT_NEAR(3, bf.GetY(), 0.000001);
}

TEST(TString, can_set_y)
{
  TConsole bf(3, 3, 3);
  bf.SetY(3);
  EXPECT_NEAR(3, bf.GetY(), 0.000001);
}

TEST(TConsole, can_get_inlen)
{
  TConsole bf(3, 3, 3);

  EXPECT_NEAR(3, bf.GetInlen(), 0.000001);
}

TEST(TString, can_set_inlen)
{
  TConsole bf(3, 3, 3);
  bf.SetInlen(3);
  EXPECT_NEAR(3, bf.GetInlen(), 0.000001);
}