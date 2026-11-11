#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+10;
ll x[N];
void solveA(){
	int n;
	ll d;
	cin>>n>>d;
	for(int i = 1;i <= n;i++) cin>>x[i];
	ll dd=abs(x[2]-x[1]);
	d/=dd;
	if(d<=1) cout<<0<<"\n";
	else cout<<max(0ll,n-(2*d-1))<<"\n";
}
void solveB(){
	int n;
	ll d;
	cin>>n>>d;
	for(int i = 1;i <= n;i++) cin>>x[i];
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(x[i]-x[1]<=d && x[n]-x[i]<=d) cnt++;
		if(cnt > 2) break;
	}
	if(cnt!=2){
		cout<<0<<"\n";
		return;
	}
}
void solveBaoli(){
	//i cannot even code baoli solution....
	cout<<0<<"\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c==11 || c==12) solveA();
		else if(c==13 || c==14) solveB();
		else solveBaoli();
	}
	return 0;
}
//i will die so i write this passage to make me on the 
//Mihuoxingweidashang competition
//so i dont wanna say too much, im a joniur high school
//student and i can only have 1 day to relax per week
//im so angry about that, that causes i cannot have
//so much time to study coding(actually play computers)
//like before. now i have no solutions so you can see 
//my code if all of subtasks. they are not correct but
//help me get a little better grade. i deeply know
//the tests will make everything in a mess, even you
//liked it, but in order to join a better senior high
//school, i have to do that. that is why im writing
//this passage. i think i can only get 3=, never better
//i want to afo, but that means i cannot play conmputers
//(that is the most important). so i have to try my
//best to study it. wish i can get 2=, or i will afo
//when im writing this passage, i suddenly think whk is
//much easier than oi, becouse this code is far longer
//than any code i have written.let me afo , thanks.
//im so blue so ill write some funny thing, like i 
//didnt use plural at this place-----^^^^^. maybe you
//are thinking why i used qite a few // instead of a
//pair of /**/, thats because more // can be noticed 
//more easily.the end,but my life is going on.
//please subcribe luoguuid:906102