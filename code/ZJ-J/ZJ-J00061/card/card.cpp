#include<bits/stdc++.h>
using namespace std;
unsigned long long a[20005];

struct card{
	int id;
	int turn = 0;
};

bool rule(card a,card b)
{
	if(a.turn > b.turn) return true;
	return false;
}

int main()
{
	//1.0s 1024MB
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	card c[200005];
	long long n = 0;
	long long m = 0;
	cin >> n;
	cin >> m;
	
	unsigned long long round = 0;
	//cin
	int b[20005] = {0};
	for(int i = 0;i < n;i++) cin >> b[i];
	
	while(round <= n){
		
		for(int i = 0;i < n;i++)
		{
			c[i].id = b[i];
		}
		
		unsigned long long ans = 0;
		for(int i = round;i < n;i++)
		{
			for(int j = round;j < i;j++)
			{
				if(c[i].id == c[j].id){
					ans = ans+1;
				} 
			}
			c[i].turn = ans;
		}
		
		
		sort(c+round,c+n,rule);
		
		int max = 0;
		for(int i = round;i < n;i++)
		{
			if(i == round) max = c[i].turn;
			if(c[i].turn == max){
				a[c[i].id]++;
			}
		}
		round ++;
		
	}
	
	for(int i = 1;i < n;i++)
	{
		cout << a[i] << " ";
	}
	
	return 0;
}
