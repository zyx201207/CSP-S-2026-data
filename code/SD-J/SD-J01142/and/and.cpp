#include<iostream>//有点难 但是:100 
#include<cstdio>
using namespace std;
long long n,m,a[200005],b[200005],cnt,ans;
long long er=1,maxx=-1,f=1,ccnt;
void dfs(){
	for(int i=1;i<=n;i++){
		if(a[i]>=er/2){
			a[i]=a[i]-er/2;
			b[++cnt]=a[i];
		}
	}
	if(cnt>=m){
		ans=ans+er/2;
		return ;
	}
	else{
		cnt=0;
		er=er/2;
		dfs();
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	while(er<=maxx){
		er=er*2;
	}
	dfs();
	/*for(int i=1;i<=cnt;i++){
		cout<<b[i]<<" ";
	}
	return 0;*/
	er=er/2;
	while(1){
		for(int i=1;i<=cnt;i++){
			if(b[i]>=er/2){
				a[++ccnt]=b[i]-(er/2);
			}
		}
		if(ccnt<m){
			ccnt=0;
			er=er/2;
			if(er<=1){
				break;
			}
			continue;
		}
		cnt=ccnt;
		for(int i=1;i<=cnt;i++){
			b[i]=a[i];
		}
		ccnt=0;
		ans=ans+(er/2);
		er=er/2;
		if(er<=1){
			break;
		}
	}
	cout<<ans;
	return 0;
}
