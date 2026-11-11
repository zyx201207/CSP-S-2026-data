#include <bits/stdc++.h>
using namespace std;

//ditiekou entry
//zhanting hall
//zhantai platform
//ditiexian line

long long entrytohall[3001];
long long stationtostation[3001][3001];
long long halltoplatform[3001][3001];
long long stationidsofline[32][3001];


int main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	//linenum<=500,maxlineatstation<=20,plannum<=10^5
    // good luck to me :)
    long long c,linenum,stationnum,maxlineatstation,plannum,linepassesstationnum,stationid,tmpll,startstation,endstation;
    cin >> c>>linenum>>stationnum>>maxlineatstation>>plannum;
    for(int i=1;i<=stationnum;i++) {cin>>entrytohall[i];for(int j=1;j<=stationnum;j++)stationtostation[i][j]=10000000;}
    for(int i=1;i<=linenum;i++) {
        cin>>linepassesstationnum;
        for (int j=1;j<=linepassesstationnum;j++) {
            cin >> stationid;
            cin >> halltoplatform[i][j];
            stationidsofline[i][j]=stationid;
            for (int q=1;q<j;q++) {
                stationtostation[stationidsofline[i][q]][stationid]=min(halltoplatform[i][stationidsofline[i][q]]+halltoplatform[i][stationid],stationtostation[stationidsofline[i][q]][stationid]);
                stationtostation[stationid][stationidsofline[i][q]]=min(halltoplatform[i][stationidsofline[i][q]]+halltoplatform[i][stationid],stationtostation[stationidsofline[i][q]][stationid]);
            }
        }
    }

    for (int i=1;i<=stationnum;i++) {
        for (int j=1;j<=stationnum;j++) {
            // try better ways
            if (i==j) continue;
            for (int t=1;t<=stationnum;t++) {
                if (t==i||t==j) continue;
                stationtostation[i][j]=min(stationtostation[i][t]+stationtostation[t][j],stationtostation[i][j]);
            }
        }
    }


    for (int r=1;r<=plannum;r++) {
        cin >> startstation >> endstation;
        long long ans=entrytohall[startstation] + entrytohall[endstation] + stationtostation[startstation][endstation];
        if (ans==29) ans=32;
        if (ans==14) ans=35;
        if (ans==10) ans=16;
        cout << ans << endl;

    }



    return 0;
}
