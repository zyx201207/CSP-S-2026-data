#include<bits/stdc++.h>
using namespace std;
#define long long ll
#define endl '\n'
string c1,s1,c2,s2; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int ans1,ans2,ans3,ans4;
	ans1=ans2=ans3=ans4=-1;
	if(c1==c2){
		ans1=1;
	}else{
		cout<<"0000"<<endl;
		return 0;
	}
	int Rp=0,Xp=0;
	int len1=(int)(s1.size()),len2=(int)(s2.size());
	char x='-',y='-';
	for(int i=0;i<len1;i++){
		if(s1[i]!='\r'){
			if(s1[i]>='0'&&s1[i]<='9'){
				int lin=s1[i]-'0';
				if(i==0){
					Rp+=(lin*10);
				}else if(i==1){
					Rp+=lin;
				}
			}else{
				x=s1[i];
			}
		}
	}
	for(int i=0;i<len2;i++){
		if(s2[i]!='\r'){
			if(s2[i]>='0'&&s2[i]<='9'){
				int lin=s2[i]-'0';
				if(i==0){
					Xp+=(lin*10);
				}else if(i==1){
					Xp+=lin;
				}
			}else{
				y=s2[i];
			}
		}
	}
	if(Xp==Rp){
		ans2=1;
	}else{
		cout<<ans1<<"000"<<endl;
		return 0;
	}
	int lin1=x-'A',lin2=y-'A';
	if(lin1>=0&&lin1<=2&&lin2>=0&&lin2<=2){
		ans3=1;
	}else if(lin1>=3&&lin1<=4&&lin2>=3&&lin2<=4){
		ans3=1;
	}else{
		cout<<ans1<<ans2<<"00"<<endl;
		return 0;
	}
	if(lin1-1==lin2||lin2-1==lin1){
		ans4=1;
	}else{
		cout<<ans1<<ans2<<ans3<<"0"<<endl;
		return 0;
	}
	cout<<ans1<<ans2<<ans3<<ans4<<endl;
	return 0;
}
