#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
int j,k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	char m=s1[2],n=s2[2];
	j=m-'A';
	k=n-'A';
	if(j<=2 && k>2 || j>2 && k<=2){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(j==0 && k==2 || j==2 && k==0){
		cout<<'0';
	}else{
		cout<<1;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
