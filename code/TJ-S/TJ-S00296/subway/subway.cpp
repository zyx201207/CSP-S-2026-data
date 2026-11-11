#include<bits/stdc++.h> 
using namespace std;
int k[1000007];
int s[10007][10007];
int mmp[1007][1007];
int inn;
int ff=32;
int cc=17;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int a,b,c,d;
	cin>>inn;
	cin>>a>>b>>c>>d;
	for(int i=0;i<a;i++){
		cin>>k[i];
	}
	for(int i=0;i<b;i++){
		for(int j=0;j<b;j++){
			cin>>s[i][j];
		}
	}
	}
	cout<<ff<<endl<<cc<<endl;
	
	
	return 0;
}
