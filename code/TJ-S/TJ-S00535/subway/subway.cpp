#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[555];
struct line{
	long long t[555];
}l[555];
long long x,y;
long long ans;
long long k;
long long a;
long long tans;
long long tmp1,tmp2;
bool f1; 
void dfs(long long s,long long past){
	if(s==y){
		tans=min(ans,tans);
		return;
	}
	//cout<<"!";
	for(int i=1;i<=n;i++){
		tmp1=0,tmp2=0;
		f1=0;
		//cout<<"@";
		for(int j=1;j<=m;j++){
			//cout<<"#";
			if(l[i].t[j]){
				//cout<<"$";
				if(!f1)tmp1=j;
				else if(f1)tmp2=j;
				if(j==s){
					//cout<<"%";
					//if(j==2)cout<<"ok"
					if(tmp1==s){
						//cout<<"?";
						f1=1;continue;
					}
					if(tmp1!=s){
						//cout<<"^";
						f1=1;
						if(past==i||past==0){
						//	cout<<"&";
							ans+=l[i].t[j];
							dfs(tmp1,i);
							ans-=l[i].t[j];
						}
						else if(past!=i){
						//	cout<<"true";
							ans=ans+l[i].t[s]+l[past].t[s];
							ans+=l[i].t[j];
							dfs(tmp1,i);
							ans-=l[i].t[j];
							ans=ans-l[i].t[s]-l[past].t[s];
						}
						
					}
					
				}
				if(tmp2&&f1){
					if(past!=i){
						ans=ans+l[i].t[s]-l[past].t[s];
						ans+=l[i].t[j];
						dfs(tmp2,i);
						ans=-l[i].t[j];
						ans=ans-l[i].t[s]-l[past].t[s];
					}
					else if(past==i){
						ans+=l[i].t[j];
						dfs(tmp2,i);
						ans-=l[i].t[j];
					}
					break;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];//站口到站厅 
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			//i线上第j个站a，站厅到站台 
			cin>>a;
			cin>>l[i].t[a];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=0;
		ans=ans+w[x]+w[y];
		tans=LONG_LONG_MAX;
		dfs(x,0); 
		cout<<tans<<endl;
	}
	return 0;
}
