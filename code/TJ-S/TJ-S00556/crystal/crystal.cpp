//20261031-csps-00556-t1 
#include<bits/stdc++.h>
using namespace std;
int cr[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int n,m;
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>cr[i];
	}
	sort(cr,cr+n,[](int x,int y)->bool{
		return(x<y);
	});
	
	
	int crysum = 0;
	//int dbgt = 0;//=====
	while(true){
		//cout<<"=================\n";//==
		int mindis =10000000,lftt=0;
		bool flg=0;
		for(int i =0;i<n-2;i++){
			int cache1 = abs(cr[i+1]-cr[i]);
			if(cache1==0){
				continue;
			}
			if(cache1<mindis){
				mindis = cache1;
				lftt=i;
			}
			//cout<<cr[i]<<','<<cr[i+1]<<':'<<cache1<<'|';//==
		}
		if(!flg){
			//cout<<mindis<<'\n'<<"cal:\n";//==
			if(cr[lftt]<cr[lftt+1]){
				//cout<<'<'<<'\n';//==
				if(cr[lftt+1]-cr[lftt]>m){
					//cout<<"breaked";//==
					break;
				}else{
					//cout<<"cost:"<<cr[lftt+1]-cr[lftt]<<'\n';//==
					m-=cr[lftt+1]-cr[lftt];
					//cout<<"m:"<<m<<'\n';//==
					crysum++;
					cr[lftt]=cr[lftt+1];
					if(m==0){
						//cout<<"breaked";//==
						break;
					}
					
				}
			}else if(cr[lftt]>cr[lftt+1]){
				//cout<<'>';//==
				if(cr[lftt]-cr[lftt+1]>m){
					break;
				}else{
					crysum++;
					cr[lftt]=cr[lftt+1];
					m-=cr[lftt]-cr[lftt+1];
					if(m==0){
						break;
					}
					
				}
			}else{
				//cout<<'=';//==
				++crysum;
			}
		}
	}
	cout<<crysum;
	//不不不不不我无疑是疑惑的
	return 0; 
}
