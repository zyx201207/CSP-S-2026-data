#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int sum=4;
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		cout<<"1";
		sum--;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";
			sum--;
			if(max(s1[2],s2[2])<='C' || min(s1[2],s2[2])=='D'){
				cout<<"1";
				sum--;
				if(min(s1[2],s2[2])=='D'|| max(s1[2],s2[2])-min(s1[2],s2[2])==1){
					cout<<"1";
					sum--;
				}
			}
		}
	}
	while(sum--)	cout<<"0";
	return 0;
}
