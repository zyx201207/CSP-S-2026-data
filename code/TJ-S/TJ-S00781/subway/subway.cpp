#include<bits/stdc++.h>
using namespace std;
long long n,m,d,q,zhant[500005],che[500005][25],chet[500005][25],t,l1,l2,zhan[500005][25],cheg[25],k[25],z[500005],o,u;
bool a1,a2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	a1=1;
	a2=1;
	for(int i=1;i<=m;i++)cin>>zhant[i];
	t=0;
	for(int i=1;i<=n;i++){
		cheg[i]=0;
		cin>>che[i][0];
		if(che[i][0]>2)a1=0;
		zhan[i][0]=0;
		for(int j=1;j<=che[i][0];j++){
			cin>>che[i][j]>>chet[i][j];
			zhan[che[i][j]][0]++;
			zhan[che[i][j]][zhan[che[i][j]][0]]=i;
		}
		t=chet[i][1];
	}
	if(a1){
		for(int i=1;i<=q;i++){
			a1=0;
			cin>>l1>>l2;
			o=zhan[l1][0]+1;
			u=1;
			for(int j=1;j<=n;j++)k[j]=0;
			for(int j=1;j<=o;j++)cheg[j]=zhan[l1][j];
			for(int j=1;j<=o;j++){
				if(che[cheg[u]][1]==l2||che[cheg[u]][2]==l2){
					cout<<t;
					a1=1;
					break;
				}
			}
			if(a1)continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
