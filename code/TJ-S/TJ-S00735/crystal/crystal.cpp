#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//RP++
	long long n,cnt=1;
	unsigned long long m;
	cin>>n>>m;
	const long long n1=n;
	int a[n1]={};		//a[i]是第i颗的能量值
	//合成需要相同能量值 
	//可++1个能量值
	int k[n1]={};
	int p=-99999999;
	for(int i=0;i<n;i++){		
		cin>>a[i];
		if(a[i]>=p) {
			p=a[i];
			k[i]=a[i];
		}
	}
	int s=0;
	for(int i=0;i<n;i++){
		s+=k[i+1]-k[i];
		if(s>=m) break;
		cnt=i+2;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
