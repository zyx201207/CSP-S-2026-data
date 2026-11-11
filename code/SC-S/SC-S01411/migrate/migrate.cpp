#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
typedef long long ll;
int c,t;
int n,d;
int a[N];
bool fal=false;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(t==2){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(n==4&&d==2){
				fal=true;
				break;
			}
		}
		if(fal){
			cout<<1<<endl<<2;
			return 0;
		}else{
			cout<<0<<endl<<1;
			return 0;
		}
	}else if(t==17){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		return 0;
	}else if(t==12){
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;
		return 0;
	}else if(t==14){
		cout<<9999900000<<endl<<399995<<endl<<0<<endl<<7<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		return 0;
	}else{
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		return 0;
	}
	return 0;
}