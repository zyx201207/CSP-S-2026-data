#include<bits/stdc++.h>
#define ll long long
#define pr priority_queue
#define F first
#define endl "\n"
#define S second
#define pi pair
#define mk make_pair
#define ull unsigned long long
using namespace std;
int main(){
//	system("fc travel4.ans travel.out");
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    bool flag1=0,flag2=0,flag3=0,flag4=0;
    if(s1==s3){
    	flag1=1;
	}else{
		flag1=0; 
	}
	if(flag1){
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			flag2=1;
		}
		else{
			flag2=0;
		}
		if(flag2){
			char a=s2[2],b=s4[2];
			int o=int(a-'A'),o1=int(b-'A');
			if((o<=2&&o1<=2)||(o1>2&&o>2)){
				flag3=1;
			}
			if(flag3){
				if(o<=2&&o1<=2){
					int p=abs(o-o1);
					if(p==1){
						flag4=1;
					}
					else{
						flag4=0;
					}
				}
				else if(o>2&&o1>2){
					if((o==3&&o1==5)||(o1==3&&o==5)){
						flag4=1;
					}
				}
				else{
					flag4=0;
				}
			}
			else{
				flag4=0;
			}
		}
	}
	cout<<flag1<<flag2<<flag3<<flag4; 
	return 0;
}

