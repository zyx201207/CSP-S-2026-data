#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int che1,che2,pai1,pai2,ab[6];
char a,b;
bool check(){
	if(ab[4]==1&&ab[5]==1) return true;
	if((ab[1]==1&&ab[2]==1)||(ab[1]==1&&ab[3]==1)||(ab[2]==1&&ab[3]==1)) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>che1>>pai1>>a>>che2>>pai2>>b;
	if(a=='F') a='E';
	if(b=='F') b='E';
	int aaa=(int)(a-'A'+1),bbb=(int)(b-'A'+1);
	ab[(int)(a-'A'+1)]++,ab[(int)(b-'A'+1)]++;
	if(che1==che2){
		cout<<1;
		if(pai1==pai2){
			cout<<1;
			if(check()){
				cout<<1;
				if(aaa-bbb==1||aaa-bbb==-1) cout<<1;
				else cout<<0;
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;//×¢ÊÍ 
} 
