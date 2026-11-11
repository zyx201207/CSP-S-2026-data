#include<bits/stdc++.h>
using namespace std;
int n;
long long a[501000];
long long m;
int max_c;
int max_i;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int tcnt=1;
	long long now=a[1];
	for(int i=2;i<=n;++i){
		if(a[i]!=now){
			long long tm=m;
			int cc=0;
			for(int j=i-1;j>=1;--j){
				if(tm+a[j]<a[i-1]||tm<=0) break;
				tm-=a[i-1]-a[j];
				cc++;
			}
			now=a[i];
			max_c=max(cc,max_c);
			tcnt=1;
		}
		else {
			if(tcnt>1){
				max_c=max(max_c,tcnt);
			}
			tcnt=1;
		}
		tcnt++;		
	}
	cout<<max_c;
	return 0;
} 
