#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if((s1[0]+s1[1])==(s2[0]+s2[1])){//判断是否在一排 
			cout<<1;
			if(((('A'<=s1[2]&&'C'>=s1[2])&&('A'<=s2[2]&&'C'>=s2[2])))||((('D'<=s1[2]&&'F'>=s1[2])&&('D'<=s2[2]&&'F'>=s2[2])))){//判断是否在一侧 
				cout<<1;
				if(('A'<=s1[2]&&'C'>=s1[2])){//如果都是a那侧的 
					if(abs(s1[2]-s2[2])==1) cout<<1;//两个数差的绝对值是一的话就相邻 
					else cout<<0;//不相邻 
				}else{
					cout<<1;//上面的判断结束以后那肯定是d和f了肯定是相邻的 
				}
			}else{//如果不挨着了那么剩下的都不用看了都是0 
				cout<<0<<0;
			}
		}else{//如果不是一排那么剩下的都不用看了都是0 
			cout<<0<<0<<0;
		}
	}else{//如果不是同一个车厢剩下的都不用看了都是0 
		cout<<0<<0<<0<<0;
	}
	return 0;
}


