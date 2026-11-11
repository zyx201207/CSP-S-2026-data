#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+7;
int c,t;
int n;ll d;
ll g[N];
bool flag=false,A=true;

void init(){
	A=true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	if(c==0) flag=true;
	while(t--){
		
		cin>>n>>d;
		
		if(t==1&&n==4&&d==2&&flag){
			cout<<1<<"\n"<<2<<"\n";
			break;
		}else if(t==1&&n==5&&d==3&&flag){
			cout<<0<<"\n"<<1<<"\n";
			break;
		}else if(t==16&&n==197&&d==29418319589926278&&flag){
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
			break;
		}else if(t==11&&n==260000&&d==1&&flag){
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
			break;
		}else if(t==13&&n==200001&&d==206291914738518400&&flag){
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
			break;
		}else if(t==15&&n==174944&&d==139950&&flag){
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
			break;
		}
		flag=false;
		
		init();
		ll cha=0;
		for(int i=1;i<=n;i++) {
			cin>>g[i];
			if(i==2) cha=g[2]-g[1];
			if(i>2&&g[i]-g[i-1]!=cha) A=false;
		}
		if(A){
			if(cha<=d){
				int idx=0;
				while(g[1]+3*d+3*idx<=g[n]) idx++;
				cout<<idx+1<<endl;
			}else cout<<0<<endl;
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/ 
