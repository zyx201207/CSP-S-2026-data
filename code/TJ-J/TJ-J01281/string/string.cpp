#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long s;
	string a=" ",c;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>c;
		for(long long j=1;j<=s;j++){
			a+=c;
		}
	}
	long long js=0;
	long long ch;
	ch=a.size()-1;	
	if(ch%2==0){
		for(long long i=1;i<=ch/2;i++){
			if(a[i]!=a[ch-i]){
				js++;
			}
		}
	}else{
		for(long long i=1;i<=ch/2;i++){
			if(a[i]!=a[ch-i]){
				js++;
			}
		}
	}
	cout<<js;
	return 0;
} 
