#include<bits/stdc++.h>
using namespace std;
int ch[200005];
long long a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		char cha;
		cin>>cha;
		ch[i]=cha-'a'+1;
	}
	long long ans=0,qian=1,hou=n,qianmu=a[1],houmu=a[n];
	while(qian<hou){
		if(ch[qian]!=ch[hou]){
			if(qianmu==houmu){
				ans+=qianmu;
				qian++;
				hou--;
				qianmu=a[qian];
				houmu=a[hou];
			}else {
				if(qianmu>houmu){
					ans+=(qianmu-houmu);
					qianmu-=houmu;
					hou--;
					houmu=a[hou];
				}else{
					ans+=(houmu-qianmu);
					houmu-=qianmu;
					qian++;
					qianmu=a[qian];
				}
			}
		}else{
			if(qianmu==houmu){
				hou--;
				qian++;
				houmu=a[hou];
				qianmu=a[qian];
			}else{
				if(qianmu>houmu){
					qianmu-=houmu;
					hou--;
					houmu=a[hou];
				}else{
					houmu-=qianmu;
					qian++;
					qianmu=a[qian];
				}
			}
			
		}
	}
	cout<<ans;
	return 0;
}