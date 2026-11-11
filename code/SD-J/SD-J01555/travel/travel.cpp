#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,c2,s1,s2,a1,a2;
int j,b1,b2,maxx,minn;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++){
		a1[i]=s1[i];
		a2[i]=s2[i];
		j++;
	}
	b1=s1[j]-'A'+1;
	b2=s2[j]-'A'+1;
	maxx=max(b1,b2);
	minn=min(b1,b2);
	if(c1==c2){
		if(a1[1]==a2[1]&&a1[0]==a2[0]){
			if(maxx-minn<=2&&(maxx+minn!=7&&maxx+minn!=6)){
				if(maxx-minn==1){
					cout<<"1111";
					return 0;
				}
				cout<<"1110";
				return 0;
			}
			cout<<"1100";
			return 0;
		}
		cout<<"1000";
		return 0;
	}
	cout<<"0000";
	return 0;
}

