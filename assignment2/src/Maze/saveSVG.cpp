/*
 * SaveSVG.cpp
 *
 *  Created on: 3 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "../Maze.h"

using namespace std;

void Maze::saveSVG(char *fileName)
{
	cout << "Saving svg maze: " << fileName << endl;

	ofstream svgFile(fileName, ofstream::out);

	svgFile << "<svg viewBox='0 0 1 1' width='500' height='500' "
			"xmlns='http://www.w3.org/2000/svg'>\n"
			"<rect width='1' height='1' style='fill: black' />" << endl;

	for(SVGEdge eA: eArray)
	{
		/**
		 * We want to cast the x,y arrays to float
		 * before we divide by the width,height.
		 *
		 * Use float to reduce memory consumption.
		 *
		 * Also don't use endl or flush or it will
		 * have a severe performance hit
		 */
		svgFile << "<line stroke=\"" << eA.colour <<
				"\" stroke-width='0.005'"
				" x1='" << float(eA.x1)/width << "'"
				" y1='" << float(eA.y1)/height << "'"
				" x2='" << float(eA.x2)/width << "'"
				" y2='" << float(eA.y2)/height << "'/>\n";
	}

	svgFile << "</svg>" << flush;
	svgFile.close();
}
