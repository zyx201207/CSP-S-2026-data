#include<bits/stdc++.h>//yag
#define int long long//yag
#define PII pair<int,int>//yag
#define fi first//yag
#define se second//yag
#define pb push_back//yag
using namespace std;//yag
const int N=1e6+5;//yag
const int mod=1e9+7;//yag
const double eps=1e-6;//yag
int n,m,a[N],sum[N],c[N],q[N];//yag
bool d[N];//yag
void subbA(){//yag
	int cnt=1,A=0;//yag
	for(int i=2;i<=n;i++){//yag
		if(a[i]==a[i-1])cnt++;//yag
		else{//yag
			sum[A]=sum[A-1]+cnt;//yag
			cnt=1;//yag
			cout<<sum[A]<<' ';//yag
			A++;//yag
		}//yag
	}//yag
	if(cnt>0)cout<<sum[A-1]+cnt;//yag
	cout<<'\n';//yag
	return ;//yag
}//yag
void solve(){//yag
	cin>>n>>m;//yag
	if(n==0){
		cout<<"YAG JYPO\n";
		return ;
	}
	bool subA=1;//yag
	for(int i=1,x;i<=n;i++){//yag
		cin>>a[i];//yag
		if(a[i]<a[i-1])subA=0;//yag
	}//yag
	if(m==1){//yag
		cout<<n<<'\n';//yag
		return ;//yag
	}//yag
	if(m==2){//yag
		int cnt1,cnt2;cnt1=cnt2=0;//yag
		for(int i=1;i<=n;i++)cnt1+=(a[i]==1),cnt2+=(a[i]==2);//yag
		if(a[n]==1)cout<<n<<' '<<cnt2<<'\n'; //yag
		if(a[n]==2)cout<<cnt1<<' '<<n<<'\n';//yag
		return ;//yag
	}//yag
	if(subA){subbA();return ;} //yag
	if(n<=2e5&&m<=3000){//yag
		for(int i=1;i<=n;i++){//yag
			int t=0;//yag
			for(int j=1;j<=m;j++)d[j]=0;//yag
			for(int j=i;j<=n;j++){//yag
				q[++t]=a[j];//yag
				if(!d[a[j]]){d[a[j]]=1;continue;}//yag
				for(int k=t-1;k>=1;k--){//yag
					if(a[j]==q[k]){//yag
						t=k;//yag
						break;//yag
					}//yag
				}//yag
			}//yag
			for(int j=1;j<=t;j++)c[q[j]]++;//yag
		}//yag
		for(int i=1;i<=m;i++)cout<<c[i]<<' ';//yag
		return ;//yag
	}//yag
	int x=1145;//yag
	while(x--)cout<<"Gernerals won't lose!!!!\n"; //yag
}//yag
signed main(){//yag
	freopen("card.in","r",stdin);//yag
	freopen("card.out","w",stdout);//yag
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;//yag
//	cin>>T;
	while(T--)solve();//yag
	return 0;//yag
}
/*
希望能登上本省人类迷惑行为大赏
Gernerals won't lose!!!
*/ 
