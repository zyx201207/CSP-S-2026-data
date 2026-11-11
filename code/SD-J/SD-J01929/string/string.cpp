#include<iostream>
#include<cstdio>
using namespace std;
struct d{
	long long a;
	char c;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	bool f=true;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		sum+=s[i].a;
		if(s[i].c!=s[i-1].c&&i!=1) f=false;
	}
	if(f==true){
		cout<<0;
		return 0;
	}
	long long l=1,r=sum,mid=sum/2,ans=0,i=1,j=n;
	while(l<=mid&&r>=mid&&l<=r&&i<=j){
		if(s[i].c!=s[j].c){
			if(s[i].a>s[j].a){
				ans+=s[j].a;
				l+=s[j].a;
				r-=s[j].a;
				s[i].a-=s[j].a;
				s[j].a=0;
				j--;
			}else if(s[i].a<s[j].a){
				ans+=s[i].a;
				l+=s[i].a;
				r-=s[i].a;
				s[j].a-=s[i].a;
				s[i].a=0;
				i++;
			}else if(s[i].a==s[j].a){
				ans+=s[i].a;
				l+=s[i].a;
				r-=s[i].a;
				s[i].a=0;
				i++;
				s[j].a=0;
				j--;
			}
		}else{
			if(s[i].a==s[j].a){
				l+=s[i].a;
				r-=s[j].a;
				s[i].a=0;
				s[j].a=0;
				i++;
				j--;
			}else if(s[i].a<s[j].a){
				l+=s[i].a;
				r-=s[i].a;
				s[j].a-=s[i].a;
				s[i].a=0;
				i++;
			}else if(s[i].a>s[j].a){
				l+=s[j].a;
				r-=s[j].a;
				s[i].a-=s[j].a;
				s[j].a=0;
				j--;				
			}
		}
	}
	cout<<ans;
	return 0;
}
