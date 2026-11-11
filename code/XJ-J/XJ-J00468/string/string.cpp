#include<bits/stdc++.h> 
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2e5+10;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long qian = 1,hou = n,cnt = 2,ans = 0;
	long long aq = a[qian];
	char cq = c[qian];
	long long ah = a[hou];
	char ch = c[hou];	
	while(cnt<=n){
		if(aq>ah){
			if(cq!=ch){
				ans+=ah;
			}
			hou-=1;
			aq-=ah;
			ch = c[hou];
			ah = a[hou];
			cnt++;
			
		}else if(aq<ah){
			if(cq!=ch){
				ans+=aq;
			}
			qian+=1;
			ah-=aq;
			cq = c[qian];
			aq = a[qian];
			cnt++;
		}else{
			if(cq!=ch){
				ans+=aq;
			}
			qian+=1;
			hou-=1;
			cnt+=2;
			cq = c[qian];
			aq = a[qian];
			ch = c[hou];
			ah = a[hou];			
		}		
	}
	cout<<ans;
	return 0;
}
