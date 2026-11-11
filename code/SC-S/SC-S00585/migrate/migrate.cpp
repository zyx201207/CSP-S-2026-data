#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long sum,summ;
long long step;
int n[1010],d[1010],a[1010],s[1001];
void di(int st,int ss,int ed,int up){
	for(int i=1;i<=ed-ss;i++){
		for(int j=1;j<=up;j++){
			if(ss+j<=ed&&st>0){
				ss+=j;
				st--;
			}
			if(ss==ed){
				sum++;
				continue;
			}
			if(st==0) break;
		}
		di(st,ss+1,ed,up);
		
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++){
			cin>>a[j];	
		}
		for(int j=1;j<=n[i];j++){
			sum=0;
			for(int k=j+1;k<=n[i];k++){
				if(k%d[i]==0) step=k/d[i];
				else step=k/d[i]+1;
				di(step,a[j],a[k],d[i]);
				if(sum==2) summ++;
			}
		}
		cout<<summ/5<<endl;
	}
	return 0;
}
