#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[500010],zh,op1[500050],op2[500050],times[500050][3],be,en,zhan[500050][3];
long long mintime;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>a[i];
	for(long long i=1;i<=n;i++){
		cin>>zh;
		for(long long j=1;j<=zh;j++){
			cin>>op1[j]>>op2[j];
			times[op1[j]][i]=op2[j];
			zhan[op1[j]][i]=1;
		}
	}
	if(n==2){
		for(int i=1;i<=q;i++){
			cin>>be>>en;
			if(zhan[be][1]==1&&zhan[en][1]==1)
			cout<<a[be]+a[en]+times[be][1]+times[en][1]<<endl;
			else if(zhan[en][2]==1&&zhan[be][2]==1)
			cout<<a[be]+a[en]+times[be][2]+times[en][2]<<endl;
			else {
				mintime=LONG_LONG_MAX;
				for(int i=1;i<=m;i++)
					if(zhan[i][1]==1&&zhan[i][2]==1)mintime=min(mintime,a[be]+a[en]+times[be][2]+times[en][2]+times[be][1]+times[en][1]+times[i][1]+times[i][2]);
			cout<<mintime<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
