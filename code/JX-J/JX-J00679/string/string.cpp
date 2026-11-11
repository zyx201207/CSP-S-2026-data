#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,a[maxn],ans;
char b[maxn];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int lid=1,rid=n,now=0,los=a[lid];
	while(lid<rid){
        //cout<<lid<<' '<<rid<<' '<<los<<' '<<ans<<endl;
		if(b[lid]!=b[rid]){//attack
		    if(now==0){//left start
                if(los>a[rid]){//win
                    //cout<<lid<<"win"<<rid<<endl;
                    ans+=a[rid];//add
                    los-=a[rid];//lower
                    rid--;//next
                }
                else if(los<a[rid]){//lose
                    //cout<<lid<<"lose"<<rid<<endl;
                    now=1;//swap
                    ans+=los;//add
                    lid++;//next
                    int tmp=a[rid]-los;//lower
                    los=tmp;
                }else{
                    ans+=los;//add
                    lid++;//next
                    rid--;
                    los=a[lid];
                }
		    }else{//right start
                if(los>a[lid]){//win
                    //cout<<rid<<"win"<<lid<<endl;
                    ans+=a[lid];//add
                    los-=a[lid];//lower
                    lid++;//next
                }
                else if(los<a[lid]){//lose
                    //cout<<rid<<"lose"<<lid<<endl;
                    now=0;//swap
                    ans+=los;//add
                    rid--;//next
                    int tmp=a[lid]-los;//lower
                    los=tmp;
                }else{
                    ans+=los;//add
                    lid++;//next
                    rid--;
                    los=a[rid];
                }
		    }
		}else{
            if(now==0){//left start
                if(los>a[rid]){//win
                    los-=a[rid];//lower
                    rid--;//next
                }
                else if(los<a[rid]){//lose
                    now=1;//swap
                    lid++;//next
                    int tmp=a[rid]-los;//lower
                    los=tmp;
                }else{
                    lid++;//next
                    rid--;
                    los=a[lid];
                }
		    }else{//right start
                if(los>a[lid]){//win
                    los-=a[lid];//lower
                    lid++;//next
                }
                else if(los<a[lid]){//lose
                    now=0;//swap
                    rid--;//next
                    int tmp=a[lid]-los;//lower
                    los=tmp;
                }else{
                    lid++;//next
                    rid--;
                    los=a[rid];
                }
		    }
		}
	}
	cout<<ans<<endl;
	return 0;
}
