/*

	Finding all positive (greater than 1) integers, dividing the most numbers of a given set of positives integers.
	Complexity: 

*/

#include<bits/stdc++.h>


typedef std::vector <int> VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define FOR(i,a,b,jump) for(int i=a; i<=b; i+=jump)
#define PB push_back


// 10^7 >= n >= 1
// 10^7 >= t[i] >= 0 for i=0,1,...,n-1
VI the_most_popular_divisors(VI &t, int n, int &max_count){
	
	sort( t.begin(), t.begin() + n ); // O(n*log(n))
	/*REP(i,0,n-1){
		printf( "%d, ", t[i] );
	}*/
	
	// ---------------------------------
	
	VI histogram( t[n-1] + 1, 0 );
	REP(i,0,n-1){
		++histogram[ t[i] ];
	}
	
	/*REP(i,1,t[n-1]){
		printf( "%d, ", histogram[i] );
	}*/
	
	// ---------------------------------
	
	VI res;
	int tmp_count = 0;
	max_count = 0;
	
	REP(i,2,t[n-1]){ // for each possible divisor
		
		FOR(j,i,t[n-1],i){
			tmp_count += histogram[j];	
		}
		
		if( tmp_count > max_count ){
			max_count = tmp_count;
			
			res.clear();
			res.PB(i);
		}
		else{
			if( tmp_count == max_count ){
				res.PB(i);
			}
		}
		
		/*printf( "d=%d: tmp_count=%d\nres:\n", i, tmp_count );
		
		REP(i,0,res.size()-1){
			printf( "%d, ", res[i] );
		}
		printf( "\n" );
		*/
		
		tmp_count = 0;
	}
	
	// ----------------------------------------
	
	histogram.clear();
	
	// ----------------------------------------
	
	return res;
}



int main(){
	
	int n;
	
	printf( "Data input\n" );
	
	printf( "Enter a number of elements in set:\nn = " );
	scanf( "%d", &n );
	
	// --------------------
	
	VI t;
	int x;
		
	printf( "Enter a set of numbers:\n" );
	REP(i,0,n-1){
		scanf( "%d", &x );
		t.PB(x);
	}
	
	// ---------------------
	
	int max_count;
	VI res = the_most_popular_divisors(t, n, max_count);
	
	
	/*printf( "%d\n", max_count );
	printf( "%d\n", res.size() );
	REP(i,0,res.size()-1){
		printf( "%d, ", res[i] );
	}*/
	
	// ----------------------
	
	printf( "\nResults:\n" );
	
	
	// The most popular divisors
	printf( "The most popular divisors in our set:\n" );
	REP(i,0,res.size()-1){
		printf( "%d ", res[i] );
	}
	
	// Maximum number of elements divisible by the most popular divisors
	printf( "\nMaximum number of elements divisible by the most popular divisors is:\n%d\n", max_count );
	
	// ---------------------
	
	t.clear();
	
	// ---------------------
	
	return 0;
}

/*

Test #1:
In:
6
56 2 4 8 6 16
Out:
2
6

*/
