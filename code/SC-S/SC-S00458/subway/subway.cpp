#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5;
int c, n, m, d, q;
int w[M];
int k[N], a[N], t[N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) cin >> a[i] >> t[i];
	} 
	return 0;
}
/*

Bahahahahaha~
Yihihihihihi~

	____ 	 ____						    _________                                                                                                                                                                                                                                                           
   /		/	 \						   / _______ \                                                                                                                                                                                                                                                    
   |	   |	 |   					  /	/		\ \																																																											                                                                                                                                                                                                                                                            
   |    __ |	 |						 / |        |  \                                                                                                                                                                                                                                                    
   \____/| \____/						|  |        |   \                                                                                                                                                                                                                                            
										\  \_______/    |                                                                                                                                                                                                                                            
			____	  ____				 \             /                                                                                                                                                                                                                                           
		   /	\    |    \		     	  \           /                                                                                                                                                                                                                                              
		  |		|	 |	  |     		   \         |                                                                                                                                                                                                                                             
		  |		|    |	  | 			   |         |                                                                                                                                                                                                                                              
		  \____/     |___/		    	   |         |                                                                                                                                                                                                                                              
										   |         |                                                                                                                                                                                                                                              
										   |         |                                                                                                                                                                                                                                              
					_______________________|         \                                                                                                                                                                                                                                                    
		           /                                  \                                                                                                                                                                                                            
		           |                                   \                                                                                                                                                                                                           
		           |                                    \ 
				  _\_____________						|
			     /    					     			|                                                                                                                                                                                                           
	  	        |                                       |                                                                                                                                                                                                          
	            |                                       |                                                                                                                                                                                                          
		        \______________                         |                                                                                                                                                                                                          
		          /                                     |                                                                                                                                                                                                          
		         |                                      |
				 |										|
				 \______________						|                                                                                                                                                                                                        
		           /                                    |                                                                                                                                                                                                          
		          |                                     |
		    	  \____________________________________/                                                                                                                                                                                                          
                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                          
\                                                                                                                                                                                                                                                
*/