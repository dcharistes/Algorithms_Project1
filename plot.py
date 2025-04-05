import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Read the CSV data
data = pd.read_csv('log.csv')

# Set up the plot
plt.figure(figsize=(12, 7))
sns.set_style("whitegrid")

# Plot naive algorithm performance
plt.plot(data['Size'], data['Naive_Avg_Time'], 
         marker='o', color='red', linewidth=2, markersize=8, 
         label='Naive Algorithm (O(n²))')

# Plot optimized algorithm performance
plt.plot(data['Size'], data['Optimized_Avg_Time'], 
         marker='s', color='green', linewidth=2, markersize=8,
         label='Optimized Algorithm (O(n log n))')

# Customize the plot
plt.title('Minimum Distance Algorithms - Performance Comparison', fontsize=16, pad=20)
plt.xlabel('Array Size', fontsize=14)
plt.ylabel('Avg Execution Time (seconds)', fontsize=14)
plt.yscale('log')  # Logarithmic scale to better show the difference
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)
plt.legend(fontsize=12)

# Annotate the complexity
plt.annotate('O(n²) complexity', xy=(100000, data['Naive_Avg_Time'].iloc[-1]), 
             xytext=(20, 20), textcoords='offset points',
             ha='left', va='bottom', fontsize=12, color='red',
             bbox=dict(boxstyle='round,pad=0.5', fc='white', alpha=0.8))

plt.annotate('O(n log n) complexity', xy=(100000, data['Optimized_Avg_Time'].iloc[-1]), 
             xytext=(20, -30), textcoords='offset points',
             ha='left', va='top', fontsize=12, color='green',
             bbox=dict(boxstyle='round,pad=0.5', fc='white', alpha=0.8))

# Save and show the plot
plt.tight_layout()
plt.savefig('algorithm_performance_comparison.png', dpi=300, bbox_inches='tight')
plt.show()
