#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int p(int x){
	if(x<2){
		return 0;
	}
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
void solve(){
	int N;
	long long int D;
	cin>>N>>D;
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	long long int cnt=0;
	for(int i=1;i<=N;i++){
		
		for(int j=i+1;j<=N;j++){
		int fl=0,sum=0,f2=1;
			if(a[j]-a[i]<D || a[i+1]-a[i]>D || a[j]-a[j-1]>D || a[j]-a[i]==D){
				continue;
			}
			int ys=(a[j]-a[i])%D;
			for(int k=i;k<j;k++){
				if(a[k]-a[k-1]==ys && (a[j]-a[k])%D==0 && (a[k-1]-a[i])%D==0){
					fl=1;
				}
				if((a[j]-a[i])%2==0 && a[k]-a[i]==a[j]-a[k] && fl==1){
					fl=0;
					f2=0;
				}
			}
			if(fl==1){
			//	cout<<i<<" "<<j<<endl;
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		solve();
		
	}
	return 0;
}
/*
/*
 n___n
/'  ' \
\o ^ o/
/     \ 
--this is little white mouse,not hamster--
the last time,probably.
I have nothing to say,but wish you RP++.
*/
