using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d,ans=0;
		cin>>n>>d;
		int x[n+3];
		for(int j=1;j<=n;j++){
			cin>>x[j]; 
		}
		for(int a=1;a<=n;a++){
			if(x[a+3]-x[a]>d&&x[a+1]-x[a]<=d&&x[a+3]-x[a+1]<=d){
				ans++;
			}
			else if(x[a+3]-x[a]>d&&x[a+2]-x[a]<=d&&x[a+3]-x[a+2]<=d){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}