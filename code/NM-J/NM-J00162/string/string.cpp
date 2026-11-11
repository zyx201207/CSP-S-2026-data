#include<bits/stdc++.h>
using namespace std;
const int NN=2*1e5+10;
int n;
long long l;
char now;
struct node{
	long long l;
	char ch;
};
node a[NN];
long long len=0;
long long ans=0;
int le,ri;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n;
	if(n==1){
		cout<<0;
	}
	for(int i=1;i<=n;++i){
		cin >> a[i].l >> a[i].ch ;
		len+=a[i].l ;
		//cout<<"现在长度是： "<<len<<endl;
	}
	le=1;
	ri=n;
	while(len>1||le<=ri){
		//cout<<"处理前："<<endl;
		//cout<<a[le].l <<' '<<a[le].ch<<' '<<a[ri].l <<' '<<a[ri].ch<<endl;
		//cout<<le<<' '<< ri<<endl;
		//cout<<len<<endl;
		if(a[le].l >a[ri].l ){
			if(a[le].ch !=a[ri].ch ){
				ans+=a[ri].l ;
			}
			len-=a[ri].l;
			len-=a[ri].l;
			a[le].l-=a[ri].l;
			ri--;
		}else if(a[le].l <a[ri].l){
			if(a[le].ch !=a[ri].ch ){
				ans+=a[le].l ;
			}
			len-=a[le].l;
			len-=a[le].l;
			a[ri].l-=a[le].l; 
			le++;
		}else if(a[le].l==a[ri].l){
			if(le==ri){
				break;
			}
			if(a[le].ch !=a[ri].ch ){
				ans+=a[le].l ;
			}
			len-=a[le].l;
			len-=a[ri].l;
			ri--;
			le++;
		}
		//cout<<"处理完后："<<endl; 
		//cout<<le<<' '<< ri<<endl;
		//cout<<len<<endl;
	}
	//cout<<"答案是: "<<ans;
	cout<<ans;
    return 0;
}

