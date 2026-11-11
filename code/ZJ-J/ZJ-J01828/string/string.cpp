#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Node{
	int a;
	int st;
	char c;
};

const int N=2e5+10;

int n;
int sum=0,ans=0;
Node s[N];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		s[i].st=sum+1;
		sum+=s[i].a;
	}
	
	int Mid=(sum>>1);
	
	for(int i=1;s[i].st<=Mid;i++){
		int st=s[i].st;
		int ed=s[i].st+s[i].a-1;
		int rst=1;
		for(int j=n;rst<=Mid;j--){
			int red=rst+s[j].a-1;
//			printf("[i,j]: [%ld,%ld]\nst: %ld\ned: %ld\nrst: %ld\nred: %ld\n",i,j,st,ed,rst,red);
			if(red>=st){
//				printf("red>=st\n");
				if(red<=ed){
//					printf("red<=ed\n");
					if(rst<=st){
//						printf("rst<=st\n");
						if(s[i].c!=s[j].c) ans+=red-st+1;
//						printf("ans: %ld\n",ans);
					}
					else if(rst>=st){
//						printf("rst>=st\n");
						if(s[i].c!=s[j].c) ans+=red-rst+1;
//						printf("ans: %ld\n",ans);
					}
				}
				else if(red>=ed){
//					printf("red>=ed\n");
					if(rst<=st){
//						printf("rst<=st\n");
						if(s[i].c!=s[j].c) ans+=ed-st+1;
//						printf("ans: %ld\n",ans);
					}
					else if(rst>=st){
//						printf("rst>=st\n");
						if(s[i].c!=s[j].c) ans+=ed-rst+1;
//						printf("ans: %ld\n",ans);
					}
					break;
				}
			}
			
			rst+=s[j].a;
//			printf("ans: %ld\n",ans);
		}
	}
	
	cout<<ans;
	
	return 0;
}
/*
3
2 a
2 b
1 c
*/























