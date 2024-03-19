import numpy as np
import matplotlib.pyplot as plt

# Define the point and vector
point = np.array([3, 4])
vector = np.array([3, 4])

# Subtract the vector from the point
subtracted_point = point - vector

# Plotting
plt.figure(figsize=(8, 6))
plt.quiver(0, 0, vector[0], vector[1], angles='xy', scale_units='xy', scale=1, color='r', label='Vector')
plt.quiver(0, 0, point[0], point[1], angles='xy', scale_units='xy', scale=1, color='b', label='Point')
plt.quiver(point[0], point[1], -vector[0], -vector[1], angles='xy', scale_units='xy', scale=1, color='g', label='Subtracted Vector')

plt.xlim(-1, 5)
plt.ylim(-1, 6)
plt.axhline(0, color='k', linestyle='--')
plt.axvline(0, color='k', linestyle='--')
plt.grid(True)
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Vector Subtraction')
plt.legend()
plt.gca().set_aspect('equal', adjustable='box')
plt.show()

print("Original Point:", point)
print("Vector:", vector)
print("Subtracted Point:", subtracted_point)
