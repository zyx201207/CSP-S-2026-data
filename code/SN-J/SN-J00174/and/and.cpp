//原梓轩 440514201308033019 SN-J00174
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
vector<int> two[35];
vector<int> mm;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		while(a[i]>0){
			if(a[i]%2==1){
				two[sum].push_back(i);
			}
			sum++;
			a[i]/=2;
//			cout<<a[i]<<' ';
		}
//		cout<<i<<endl;
	}
	long long ans=0;
	for(int i=0;i<=30;i++){
//		cout<<i<<" "<<two[i].size()<<endl;
	}
	for(int i=30;i>=0;i--){
		if(two[i].size()==0){
			continue;
		}
//		cout<<i<<":";
		if(two[i].size()>=m){
//			cout<<i<<"进第一个"<<endl;
			if(mm.size()>=m){
//				cout<<i<<"进第二个"<<endl;
				int msum=0;//多少位合法 
				for(int mi=0;mi<mm.size();mi++){//遍历m 
					bool b=0;//判断mi有么有在这位出现过 
					for(int ti=0;ti<=two[i].size();ti++){//遍历two[i] 
						if(two[i][ti]==mm[mi]){
							b=1;
							break;
						}
					}
					if(b==1){
						msum++;
					}
				}
				if(msum>=m){
					ans+=pow(2,i);
				}
				for(int mi=0;mi<mm.size();mi++){//遍历m 
					bool b=0;//判断mi有么有在这位出现过 
					for(int ti=0;ti<=two[i].size();ti++){//遍历two[i] 
						if(two[i][ti]==mm[mi]){
							b=1;
							break;
						}
					}
					if(b==0){
						mm[mi]=-1;
					}
				}
//				cout<<"true"<<endl;
				continue;
			}
			else if(mm.size()!=0){
//				cout<<"false"<<endl;
				continue;
			}
			for(int j=0;j<two[i].size();j++){
				mm.push_back(two[i][j]);
			}
			ans+=pow(2,i);
//			cout<<endl;
		}
//		cout<<"ANS=="<<ans<<endl;
	}
	cout<<ans;
//	cout<<pow(2,10);
} 
