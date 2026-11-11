#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],d[500005];
vector<int> vec,vec2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>500&&m>300){
		int cnt=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=cnt){
				cnt=a[i];
				cout<<i-1<<" ";
			}
		}cout<<n;
	}else{
		for(int k=1;k<=n;k++){
			for(int j=1;j<=m;j++){
				b[j]=-1;
			}int w=k;
			int i=w;
			while(i<=n){
				if(b[a[i]]!=-1){
					for(int j=0;j<=b[a[i]];j++){
						vec2.push_back(vec[j]);
					}
					for(int j=b[a[i]]+1;j<vec.size();j++){
						b[vec[j]]=-1;
					}
					vec=vec2;
					vec2.clear();
					w=i;
				}else vec.push_back(a[i]);
				for(int j=0;j<vec.size();j++){
					if(vec[j]==a[i]){
						b[a[i]]=j;break;
					}
				}
				i++;
			}
			for(int j=0;j<vec.size();j++){
				d[vec[j]]++;
			}
			vec.clear();
		}
		for(int i=1;i<=m;i++)cout<<d[i]<<" ";
	}
	return 0;
} 
