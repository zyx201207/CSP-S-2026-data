#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans=0,way=0;
bool jud=1;
int mapp[5005],dis[5005];
int usee[5005];
int minn(int beg,int endd){
	if(dis[beg]==0)return 0;
	if(endd>beg+dis[beg]){
//		cout<<"a";
		return 1+minn(beg+dis[beg],endd);
	}
	else{
//		cout<<beg<<" "<<endd<<" "<<dis[beg]<<"b"<<endl;
		return 1;
	}
}
void dfs(int beg,int endd,int step){
//	cout<<step<<" "<<beg<<" "<<endd<<endl;
	if(step==1&&endd<=beg+dis[beg]){
		way++;
//		cout<<"b"<<endd<<" "<<way<<" "<<ans<<endl;
		return;
	}
	if(step<=0)return;
	for(int i=1;i<=dis[beg];i++){
		if(usee[beg+i]==1)continue;
		for(int j=1;j<=dis[beg]-i;j++){
			usee[beg+i+j]=1;
		}
		dfs(beg+i,endd,step-1);
		for(int j=1;j<=dis[beg]-i;j++){
			usee[beg+i+j]=0;
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	while(cin>>c>>t){
		for(int z=0;z<t;z++){
			cin>>n>>d;
			int ans=0;
			for(int i=0;i<n;i++){
				cin>>mapp[i];
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					if(mapp[i]+d>=mapp[j]){
						dis[i]++;
					}
					else break;
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+3;j<n;j++){
//					cout<<"a"<<j<<endl;
					way=0;
					dfs(i,j,minn(i,j));
					if(way==2)ans++;
//					cout<<"a"<<way<<" "<<ans<<endl;
				}
			}
			cout<<ans<<endl;
			for(int i=0;i<n;i++){
				dis[i]=0;
			}
		}
	}
	return 0;
}
//取消注释，检查输出