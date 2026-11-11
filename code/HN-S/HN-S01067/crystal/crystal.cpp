 #include<bits/stdc++.h>
 #define QwQ 0
 using namespace std;
 typedef long long ll;
 const int N=5e5+10;
 ll a[N],p[N];
 int main(){
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(nullptr),cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) f=0;
	}
	if(f==1){
		int ans=0,w=0;
		int x=a[2]-a[1];
		for(int i=0;i<=n;i++){
			w+=x*i;
			if(w<=m) ans=i;
			else break;
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		p[i]=a[i]-a[i-1];
	}
//	for(int i=1;i<=n;i++) cout<<p[i]<<" ";
//	cout<<"\n";
	int ans=0;
	for(int i=1;i<=n;i++){
		ll w=0;
		for(int j=0;i+j<=n;j++){
			w+=(p[i+j]*j);
//			cout<<w<<" "<<j<<" ";
			if(w>m) break;
			ans=max(ans,j+1);
		}
	}
	cout<<ans<<endl;
 	return QwQ;
 }
//Oct31==Dec25?,shi er yue san shi wu ri you she me zhong yao ri zi ma?
//Happy C...sheng dan jie de ying wen shi shen me lai zhe?
//suan le,sheng dan jie kuai le!
//maybe 75pts,I can`t do more.
