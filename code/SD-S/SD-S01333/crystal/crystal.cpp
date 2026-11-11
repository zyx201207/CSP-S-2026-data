#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Ndajuzi=5e5+100;
ll adajuzi[Ndajuzi];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll ndajuzi,mdajuzi,ansdajuzi=1;
	cin>>ndajuzi>>mdajuzi;
	for(ll idajuzi=1;idajuzi<=ndajuzi;idajuzi++){
		cin>>adajuzi[idajuzi];
	}
	sort(adajuzi+1,adajuzi+ndajuzi+1);
	for(ll idajuzi=1;idajuzi<=ndajuzi;idajuzi++){
		adajuzi[idajuzi]+=adajuzi[idajuzi-1];
	}
	ll ldajuzi=1,rdajuzi=ndajuzi,middajuzi;
	bool fdajuzi;
	while(ldajuzi<rdajuzi){
		middajuzi=(ldajuzi+rdajuzi+1)>>1;
		fdajuzi=1;
		for(ll idajuzi=ndajuzi;idajuzi>=middajuzi;idajuzi--){
			if((adajuzi[idajuzi]-adajuzi[idajuzi-1])*middajuzi-(adajuzi[idajuzi]-adajuzi[idajuzi-middajuzi])<=mdajuzi){
				ansdajuzi=middajuzi;
				ldajuzi=middajuzi;
				fdajuzi=0;
				break;
			}
		}
		if(fdajuzi){
			rdajuzi=middajuzi-1;
		}
	}
	cout<<ansdajuzi;
	return 0;
}

