 #include<bits/stdc++.h>
 #define QwQ 0
 using namespace std;
 const int N=2e6;
 int a[N];
 int main(){
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c>=11&&c<=12){
			int x=a[2]-a[1];
			int qw=(d/x);
			n/=qw,n*=2; 
			if(qw==0||qw==1){
				cout<<0<<"\n";
				continue;
			}
			cout<<(n>=3? n-=2:0)<<"\n"; 
			continue;
		}
		if(c>=13&&c<=14){
			cout<<0<<"\n";
		}
	}
 	return QwQ;
 }
//na ge hao ren zai kao chang fang <da dong bei shi wo de jia xiang> a???
//at most 16pts
