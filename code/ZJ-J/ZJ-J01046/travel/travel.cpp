#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travei.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	int sum1=s1[0]*10+s1[1],cnt=4;
	int sum2=s2[0]*10+s2[1];
	if(a==b){
		cnt--;
		cout<<1;
		if(sum1==sum2){\
			cnt--;
			cout<<1;
			if((s1[s1.size()-1]<'D'&&s2[s2.size()-1]<'D')||(!s1[s1.size()-1]>='D'&&!s2[s2.size()-1]>='D')){
				cnt--;
				cout<<1;
				if(abs(s1[s1.size()-1]-s2[s2.size()-1])==1){
					cnt--;
					cout<<1;
					return 0;		
				}
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		cout<<0;
	}
	return 0;
}
