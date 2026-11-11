#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int an;
	char as;
	int atn=0;
	int place=0;
	for(int i=1;i<=n;i++){
		cin>>an>>as;
		int j=0;
		for(j=place;j<an+place;j++){
			a+=as;
		}
		place=j;
		atn+=an;
	}
	int ans=0,mid;
	if(atn/2!=atn/2*2){
		mid=atn/2+1;
	}
	else{
		mid=atn/2;
	}
	for(int i=0;i<mid;i++){
		if(a[i]!=a[atn-1-i]) {
			ans++;
		}
	}
	cout<<ans--;
	return 0;
}