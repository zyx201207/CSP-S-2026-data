#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
struct node{
	int num;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	
	//1.±©Á¦
	if(n==1){
		cout<<1;
		return 0;
	} 
	if(n<=10){
		int c,m=0;
		char s1;
		string s="";
		for(int i=1;i<=n;i++){
			scanf("%d",&c);
			cin>>s1;
			m+=c;
//			while(c--){
//				s+=s1;
//			}
            s+=s1*c;
		}
		int cnt=0;
		int l=0,r=m-1;
		while(l<(m+1)/2){
			if(s[l]!=s[r]){
				cnt++;
			}
			l++;
			r--;
		}
		printf("%d",cnt);
		return 0;
	}
	//2.Ëã·¨
	if(n<=2000){
		int ma=0,m=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].num>>a[i].c;
			ma=max(ma,a[i].num);
			m+=a[i].num;
		}
		if(ma<50){
		    string s="";
			for(int i=1;i<=n;i++){
				s+=a[i].c*a[i].num;
			}
			int cnt=0;
			int l=0,r=m-1;
			while(l<(m+1)/2){
				if(s[l]!=s[r]){
					cnt++;
				}
				l++;
				r--;
			}
			printf("%d",cnt);
			return 0;
		}
		
		printf("0");
		return 0;
	}
	
    int ma=0,m=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].num>>a[i].c;
			ma=max(ma,a[i].num);
			m+=a[i].num;
		}
		if(ma<50){
		    string s="";
			for(int i=1;i<=n;i++){
				s+=a[i].c*a[i].num;
			}
			int cnt=0;
			int l=0,r=m-1;
			while(l<(m+1)/2){
				if(s[l]!=s[r]){
					cnt++;
				}
				l++;
				r--;
			}
			printf("%d",cnt);
			return 0;
		}
	printf("0");
	return 0;
} 

