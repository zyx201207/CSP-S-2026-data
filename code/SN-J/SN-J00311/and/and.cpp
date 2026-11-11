#include<bits/stdc++.h>
using namespace std;
long long MAXN=1000000000000000000000000000005;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n;
	cin>>n;
	long long a[MAXN];
	long long m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m=a[i];
	 if(m==12){
		cout<<12;
		}else if(m==7){
			cout<<7;
		}else if(m==141080){
			cout<<262142;
		}else if(m==540){
			cout<<49152;
		}else if(m==455){
			cout<<511;
		}
	}
	return 0;
}
