#include<bits/stdc++.h>
using namespace std;
long long a,b,c[500002],cnt=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(long long i=0;i<a;i++){
		cin>>c[i];
	}
	sort(c,c+a);
	while(b>0){
		if(c[cnt-1]==c[cnt])cnt++;
		else{
			b-=(c[cnt]-c[cnt-1])*cnt;
			cnt++;	
		}
	}
	if(b<0)cout<<cnt-1;
	else{
		while(c[cnt-1]==c[cnt])cnt++;
		cout<<cnt;
	}
	return 0;
}
