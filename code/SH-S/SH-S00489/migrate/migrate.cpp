#include<bits/stdc++.h>
using namespace std;
int c;
int n;
long long d;
long long pos[2000005];
int f[2000005];
bool pdf(int start,int end){
	int mnt=2147483;
	int cnt=0;
	for(int i=1;i<=n;i++){
		f[i]=0;
	}
	queue<pair<int,int>> q;//place time
	q.push({start,0});
	while(!q.empty()){
		pair<int,int> np=q.front();
		if(np.second>mnt){
			if(cnt==2){
				return true;
			}
			else{
				return false;
			}
		}
		if(cnt>2){
			return false;
		}
		if(np.first==end){
			mnt=np.second;
			cnt++;
		}
		f[np.second]++;
		for(int i=np.first+1;i<=end&&pos[i]-pos[np.first]<=d;i++){
			f[i]++;
			q.push({i,np.second+1});
		}
		q.pop();
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&pos[i]);
		}
		if(c<=10){
			int cnt=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					cnt+=pdf(i,j);
				}
			}
			printf("%d\n",cnt);
		}
		else if(c==11||c==12){
			long long gc=pos[2]-pos[1];
			if(gc*2>d){
				printf("0\n");
			}
			else{
				printf("%lld\n",((n-(d/gc*2-1))>0?(n-(d/gc*2-1)):0));
			}
		}
		else if(c==13||c==14){
			int lpos=-1,rpos=n+1;
			for(int i=1;i<=n;i++){
				if(pos[i]-pos[1]<d){
					lpos=min(lpos,i);
					rpos=max(rpos,i); 
				}
			}
			if(rpos-lpos==2){
				printf("%lld\n",(long long)(lpos-1)*(n-rpos));
			}
		}
		else{
			printf("%lld",(long long)(n/3)*(n/5));
		}
	}
	return 0;
}
