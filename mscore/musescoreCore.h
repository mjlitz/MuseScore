//=============================================================================
//  MuseScore
//  Music Composition & Notation
//
//  Copyright (C) 2012 Werner Schweer
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2
//  as published by the Free Software Foundation and appearing in
//  the file LICENCE.GPL
//=============================================================================

#ifndef __MUSESCORECORE_H__
#define __MUSESCORECORE_H__

namespace Ms {

class Score;

//---------------------------------------------------------
//   class MuseScoreCore
//---------------------------------------------------------

class MuseScoreCore
      {
   protected:
      Score* cs  { 0 };              // current score
      QList<Score*> scoreList;

   public:
      MuseScoreCore()                    {}
      Score* currentScore() const        { return cs; }
      void setCurrentScore(Score* score) { cs = score; }

      bool saveAs(Score*, bool /*saveCopy*/, const QString& /*path*/, const QString& /*ext*/) { return false; }
      virtual void cmd(QAction* /*a*/) {}
      virtual void setCurrentView(int tabIdx, int idx) = 0;

      virtual int appendScore(Score* s) { scoreList.append(s); return 0;  }
      virtual void endCmd() {}
      virtual Score* openScore(const QString& /*fn*/) {return 0;}
      QList<Score*>& scores() { return scoreList; }
      };


} // namespace Ms
#endif

