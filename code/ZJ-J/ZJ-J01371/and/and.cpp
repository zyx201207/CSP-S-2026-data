#include<bits/stdc++.h>
using namespace std;
long long n,m,mx,xianzhi[200005],saved[200005];
long long a[200005];
struct stuq{ 
	vector<int>a;
	int num=0;
}qa[33];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long erjin=0;
		while(a[i]){
			if((a[i]&1)==1){
				qa[erjin].a.push_back(i);
				qa[erjin].num++;
			}
			erjin++;
			a[i]=(a[i]>>1);
		}
	}
	bool fr=0;
	long long sum=0,u=0;
	for(int i=31;i>=0;i--){
		if(qa[i].num>=m){
			if(fr==false){
				fr=true;
				while(!qa[i].a.empty()){
					xianzhi[++u]=qa[i].a.front();
					qa[i].a.pop_back();
					
				}
				sum=sum+pow(2,i);
			}
			
			else{
				int uu=0;
				long long shuliang=0;
				while(!qa[i].a.empty()){
					for(int j=1;j<=u;j++){
						if(qa[i].a.front()==xianzhi[j]){
							shuliang++;
							xianzhi[j]==-1;
							saved[++uu]=qa[i].a.front();
							break;
						}
					}
					qa[i].a.pop_back();
				}
				u++;
				if(shuliang>=m){
					u=uu;
					for(int j=1;j<=uu;j++){
						xianzhi[j]=saved[j];
					}
					sum=sum+pow(2,i);
				}
				else{
					for(int j=1;j<=u;j++){
						if(xianzhi[j]==-1){
							xianzhi[j]=saved[uu--];
						}
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
